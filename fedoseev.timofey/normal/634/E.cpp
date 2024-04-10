#include <iostream>	
#include <string>	
#include <vector>	
#include <queue>	
#include <deque>	
#include <stack>	
#include <set>	
#include <map>	
#include <unordered_map>	
#include <unordered_set>	
#include <cstring>	
#include <cmath>	
#include <cstdlib>	
#include <algorithm>	
#include <random>	
#include <iomanip>	
#include <functional>	
#include <cassert>	
 	
typedef long long ll;
 
using namespace std;	
 
const int N = 2e5 + 7;
const int Inf = 1e9 + 7;
 
vector <int> g[N];
int sz[N];
int mark[N];
 
int can = 0;
 
int dfs(int u, int p) {
  sz[u] = 1;
  int mx1 = 0, mx2 = 0;
  int sum = 1;
  for (auto v : g[u]) {
    if (v != p) {
      int x = dfs(v, u);
      sz[u] += sz[v];
      if (x == sz[v]) {
        sum += x;
      } else {
        if (x > mx1) swap(x, mx1);
        if (x > mx2) swap(x, mx2);
      }
    }
  }
  if (!mark[u]) return 0;
  can = max(can, sum + mx1 + mx2);
  return sum + mx1;
} 
 
int main() {	
  ios_base::sync_with_stdio(false); cin.tie(0);	
#ifdef LOCAL	
  freopen("input.txt", "r", stdin);	
#endif	
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int l = 0, r = 1e9 + 1;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    for (int i = 0; i < n; ++i) {
      mark[i] = (a[i] >= m);
    }
    for (int i = 0; i < n; ++i) {
      sz[i] = 0; 
    }
    can = 0;
    bool fl = false;
    for (int i = 0; i < n; ++i) {
      if (!mark[i]) {
        dfs(i, -1);
        fl = true;
        break;
      }
    }
    if (!fl) dfs(0, -1);
    if (can >= k) l = m;
    else r = m;
  }
  cout << l << '\n';
}