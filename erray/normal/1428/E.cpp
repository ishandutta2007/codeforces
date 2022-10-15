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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto sq = [&](int x) {
    return 1LL * x * x;
  };

  auto val = [&](int x, int c) {
    int nom = x % c;
    int norm = c - nom;
    return 1LL * norm * sq(x / c) + 1LL * nom * sq(x / c + 1); 
  };

  auto cost = [&](int ind, int x) {
    return val(a[ind], x) - val(a[ind], x + 1); 
  };

  auto cmp = [&](auto x, auto y) {
    return cost(x.first, x.second) < cost(y.first, y.second);  
  };
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    pq.emplace(i, 1);
    ans += sq(a[i]);
  }

  k -= n;
  while (k--) {
    auto[ind, piece] = pq.top();
    debug(ans, pq.top());    
    pq.pop();
    ans -= cost(ind, piece);
    if (piece < a[ind]) {
      pq.emplace(ind, piece + 1);
    }
  }
  cout << ans << '\n';
}