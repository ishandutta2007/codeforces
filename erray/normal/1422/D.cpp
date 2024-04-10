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
  int foo, n;
  cin >> foo >> n;
  int sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  vector<pair<int, int>> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i].first >> d[i].second;
  }

  vector<vector<pair<int, int>>> g(n + 1);
  auto Add = [&](int x, int y, int w) {
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
  };
  
  d.emplace_back(sx, sy);
  ++n;
  sort(d.begin(), d.end());
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return d[x].second < d[y].second;
  });
  
  for (int i = 1; i < n; ++i) {
    Add(i, i - 1, d[i].first - d[i - 1].first);
  }
  for (int i = 1; i < n; ++i) {
    Add(ord[i], ord[i - 1], d[ord[i]].second - d[ord[i - 1]].second);
  }
  debug(g);
    
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<bool> vis(n);
  vector<int> sp(n);
  for (int i = 0; i < n; ++i) {
    pq.emplace(abs(sx - d[i].first) + abs(sy - d[i].second), i);
  }
  while (!pq.empty()) {
    auto[w, v] = pq.top();
    pq.pop();
    debug(v, w);
    if (vis[v]) continue;
    vis[v] = true;
    sp[v] = w;
    for (auto[u, l] : g[v]) {
      if (!vis[u]) {   
        debug(w + l, u);
        pq.emplace(w + l, u);
      }
    }
  }
  long long ans = LLONG_MAX;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, 0LL + abs(d[i].first - fx) + abs(d[i].second - fy) + sp[i]);        
  }  
  debug(d, sp);
  cout << ans << '\n';  
}