// author: erray
#include<bits/stdc++.h>
 
using namespace std;

template<typename T, typename F> string to_string(pair<T, F> p);
template<typename T, typename F, typename Tr> string to_string(tuple<T, F, Tr> p);
template<typename T, typename F, typename Tr, typename Th> string to_string(tuple<T, F, Tr, Th> p);
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(char c) {
  return (string) "'" + c + "'";
}
string to_string(const char* p) {
  return to_string((string) p);
}
string to_string(bool B) {
  return (B ? "true" : "false");
}
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if ((int) res.size() > 1) res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}
template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& el : v) {
    if ((int) res.size() > 1) res += ", ";
    res += to_string(el);
  }
  res += "}";
  return res;
}
template<typename T, typename F> string to_string(pair<T, F> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename T, typename F, typename Tr> string to_string(tuple<T, F, Tr> p) {
  return '(' + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ')';
}
template<typename T, typename F, typename Tr, typename Th> string to_string(tuple<T, F, Tr, Th> p) {
    return '(' + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ')';
}
void debug_out() {
  cerr << endl;
}
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" , debug_out(__VA_ARGS__)
#else
#define debug(...) (void) 37
#endif
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int c = 0;
  long long ans = 0;  
  int best = 0;

  for (int bit = 0; bit < 32; ++bit) {
    debug(bit);
    c += (1 << bit);
    vector<int> cur(n);
    for (int i = 0; i < n; ++i) {
      cur[i] = a[i] - (a[i] & c); 
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      if (cur[x] != cur[y]) {
        return cur[x] < cur[y];
      }
      return x < y;
    });
    vector<vector<int>> inds(2);
    if (bit < 5) debug(ord, cur);

    auto check = [&](int con) {
      int p = 0;
      long long res = 0;
      for (int i = 0; i < (int) inds[con].size(); ++i) {
        while (p < (int) inds[con ^ 1].size() && inds[con ^ 1][p] < inds[con][i]) {
          ++p;
        }
        res += p;
      }
      return res; 
    };
    
    int lst = -1;
    vector<long long> tot(2);
    for (int i = 0; i < n; ++i) {
      if (lst != cur[ord[i]]) {
        tot[1] += check(1);
        tot[0] += check(0);
        debug(inds);
        inds[0].clear();
        inds[1].clear();
      }
      inds[(a[ord[i]] & (1 << bit)) > 0].push_back(ord[i]);
      lst = cur[ord[i]];
    }
    tot[1] += check(1);
    tot[0] += check(0);
    debug(inds);
    inds[0].clear();
    inds[1].clear();
    debug(tot);

    if (tot[1] < tot[0]) {
      ans += tot[1];
      best += (1 << bit);
    } else {
      ans += tot[0];
    }
  }
  cout << ans << ' ' << best << '\n';
}