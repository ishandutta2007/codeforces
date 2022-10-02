#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 2005;


int n, m;
bitset<2005> a[MAXN];
int w[MAXN][MAXN];
int parent[MAXN];
vector<int> who[MAXN];
vector<int> g[MAXN];


int findset(int v) {
   if (v == parent[v]) {
      return v;
   }
   return parent[v] = findset(parent[v]);
}



int col[MAXN];
int uk = 0;


int dfs(int u, int pr = -1) {
   int cnt = 1;
   for (auto h: g[u]) {
      if (h == pr || col[h] != uk) {
         continue;
      }
      cnt += dfs(h, u);
   }
   return cnt;
}


bool check(vector<int> x) {
   uk++;
   for (auto y: x) {
      col[y] = uk;
   }
   return dfs(x[0]) == sz(x);
}

void solve() {
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      a[i].reset();
      parent[i] = i;
      g[i].clear();
   }
   for (int i = 0; i < m; i++) {
      string s;
      cin >> s;
      who[i].clear();
      for (int j = 0; j < n; j++) {
         if (s[j] == '1') {
            who[i].pb(j);
            a[j][i] = 1;
         }
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         w[i][j] = (a[i] & a[j]).count();
      }
   }
   vector<pair<int, pair<int, int> > > st;
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         st.pb({w[i][j], mp(i, j)});
      }
   }
   sort(all(st));
   reverse(all(st));
   vector<pair<int, int> > sts;
   for (auto x: st) {
      int ta = x.second.first;
      int tb = x.second.second;
      if (findset(ta) != findset(tb)) {
         parent[findset(ta)] = findset(tb);
         sts.pb(mp(ta, tb));
         g[ta].pb(tb);
         g[tb].pb(ta);
      }
   }
   bool bad = false;
   for (int i = 0; i < m; i++) {
      if (!check(who[i])) {
         bad = true;
         break;
      }
   }
   if (bad) {
      cout << "NO\n";
      return ;
   }
   cout << "YES\n";
   for (auto x: sts) {
      cout << x.first + 1 << ' ' << x.second + 1 << '\n';
   }
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
 	//read(FILENAME);	
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
}