#include <bits/stdc++.h>
using namespace std;


#define int long long
#define endl "\n"
using ii = pair<int, int>;

int n;


const int inf = 1e9;
const int ms = 2e5+5;


ii thi[2*ms], tlo[2*ms];
vector<int> d;
queue<int> q;
vector<int> p;

void build() {
  for(int i = 0; i < n; i++) {
    thi[i+n] = {i+p[i], i};
    tlo[i+n] = {i-p[i], i};
  }
  tlo[n+n] = {inf, inf};
  thi[n+n] = {-1, -1};
  for(int i = n - 1; i > 0; --i) {
    tlo[i] = min(tlo[i<<1],tlo[i<<1|1]); // Merge
    thi[i] = max(thi[i<<1],thi[i<<1|1]); // Merge
  }
}

void updatelo(int p, int value) { // set value at position p
  for(tlo[p += n] = {value, p}; p > 1; p >>= 1) tlo[p>>1] = min(tlo[p] , tlo[p^1]); // Merge
}

ii querylo(int l, int r) {
  ii res = {inf, inf};
  r = min(r, n-1);
  l = max(0ll, l);
  for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    if(l&1) res = min(res, tlo[l++]); // Merge
    if(r&1) res = min( res, tlo[--r]); // Merge
  }
  return res;
}

void updatehi(int p, int value) { // set value at position p
  for(thi[p += n] = {value, p}; p > 1; p >>= 1) thi[p>>1] = max(thi[p] , thi[p^1]); // Merge
}

ii queryhi(int l, int r) {
  ii res = {-1, -1};
  r = min(r, n-1);
  l = max(0ll, l);
  for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    if(l&1) res = max(res, thi[l++]); // Merge
    if(r&1) res = max( res, thi[--r]); // Merge
  }
  return res;
}


void add(int i, int k) {
  d[i] = k;
  q.emplace(i);
  updatehi(i, -1);
  updatelo(i, inf);
}

void solve() {
  build();
  int x, y;
  cin >> n >> x>>y;
  p.resize(n);
  x--; y--;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  build();
  d.assign(n, inf);
  add(x, 0);
  // for(int i = 0; i < 2*n; i++) {
  //   cout << thi[i].first << " ";
  // }
  // cout << endl;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    // cout << " LETS " << x << endl;
    auto help = querylo(x, x+p[x]);
    while(help.first <= x) {
      // cout << " T1 "  << help.first << "  " << help.second << endl;
      add(help.second, d[x]+1);
      help = querylo(x, x+p[x]);
    }
    help = queryhi(x-p[x], x);
    while(help.first >= x) {
      // cout << " T2 "  << help.first << "  " << help.second << endl;
      add(help.second, d[x]+1);
      // if(queryhi(x-p[x], x) == help) {
      //   return;
      // }
      help = queryhi(x-p[x], x);
    }
  }
  // for(int i = 0; i < n; ++i) {
  //   cout << d[i] << " ";
  // }
  // cout << endl;
  cout << d[y] << endl;
}

 main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}