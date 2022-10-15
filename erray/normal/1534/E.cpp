// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 template<typename A, typename B> string to_string(pair<A, B> p);
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t);
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t);

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(char c) {
  return string("'") + c + "'";
}

string to_string(const char* c) {
  return to_string(string(c));
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}

string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < int(v.size()); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& e : v) {
    if (int(res.size()) > 1) {
      res += ", ";
    }
    res += to_string(e);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(pair<A, B> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + '}';
}
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + '}';
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << "  " << to_string(H);
  debug_out(T...);
}

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(37)
#endif
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<bool>> in(n + 1, vector<bool>(n));
  vector<int> par(n + 1, -1);
  vector<vector<int>> moves(n + 1);
  vector<int> sp(n + 1, -1);
  sp[0] = 0;
  queue<int> que;
  que.push(0);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    debug(v);
    for (int j = 0; j <= k; ++j) {
      int next = v + (k - j) - j;
      if (j > v || (k - j) > (n - v) || sp[next] != -1) {
        continue;
      } 
      in[next] = in[v];
      sp[next] = sp[v] + 1;
      par[next] = v;
      que.push(next);
      array<int, 2> left = {k - j, j};
      for (int i = 0; i < n; ++i) {
        if (left[in[next][i]]) {
          left[in[next][i]] -= 1;
          moves[next].push_back(i);
          in[next][i] = bool(in[next][i]) ^ 1;
        }
      }
      assert(int(moves[next].size()) == k);
    }
  }

  if (sp[n] == -1) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  int v = n;
  while (v != 0) {
    cout << "? ";
    for (auto e : moves[v]) {
      cout << e + 1 << ' '; 
    }
    cout << endl;
    int res;
    cin >> res;
    ans ^= res;
    v = par[v];
  }
  cout << "! " << ans << endl;
}