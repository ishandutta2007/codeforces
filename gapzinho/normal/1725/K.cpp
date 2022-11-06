#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f3f3f3f3f;
 
const int ms = 1e6+5;
const int mod = 998244353;

int ans = 0;

set<int> eles[ms];
int root[ms];
int height[ms];
int z = 0;
map<int, int> sth;

void join(int u, int v) {
  if(eles[u].size() < eles[v].size()) {
    swap(u, v);
  }
  for(int x : eles[v]) {
    eles[u].emplace(x);
    root[x] = u;
  }
  sth[height[u]] = u;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    root[i] = z++;
    eles[root[i]].emplace(i);
    cin >> height[root[i]];
    if(!sth.count(height[root[i]])) {
      sth[height[root[i]]] = root[i];
    } else {
      join(sth[height[root[i]]], root[i]);
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int typ;
    cin >> typ;
    if(typ == 1) {
      int k, w;
      cin >> k >> w;
      k--;
      eles[root[k]].erase(k);
      root[k] = z++;

      eles[root[k]].emplace(k);
      height[root[k]] = w;
      if(!sth.count(w)) {
        sth[w] = root[k];
      } else {
        join(sth[w], root[k]);
      }
    } else if(typ == 2) {
      int k;
      cin >> k;
      k--;;
      cout << height[root[k]] << '\n';
    } else {
      int l, r;
      cin >> l >> r;
      auto it = sth.lower_bound(l);
      vector<int> torem;
      while(it != sth.end() && it->first <= r) {
        torem.emplace_back(it->first);
        it++;
      }
      for(auto x : torem) {
        int p = sth[x];
        int newheight = x-l < r-x ? l-1 : r+1;
        sth.erase(x);
        height[p] = newheight;
        if(!sth.count(newheight)) {
          sth[newheight] = p;
        } else {
          join(sth[newheight], p);
        }
      }
    }
  }
}
 
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}