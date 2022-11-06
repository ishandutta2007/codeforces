/*
Author : Hocky Yudhiono
Min 04 Sep 2022 12:35:45

1. You can sort the query if offline!
2. Don't bring the dp remaining state when dfsing on DP on Tree.
3. Try to reverse (Think from the back) if you stuck.
4. Be careful when submitting Div. 2 D-F, dont waste it on stupid WAs.
5. Try to reduce a problem, think of it when you're making subtasks
   like when problemsetting.
6. Matching problems can be solved with DP and vice versa.
   Counting and optimizing problems can be solved with DP.
   Try bitmasking when N is small. When big, consider greedy-ing.
7. map<string,int> is faster than you think

*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

// Suffix Literal:
// U: Unsigned
// L: Long double
// LL: Long long
typedef long long ll;
typedef long long LL;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef pair<ll, ll> PLL;
typedef pair<ll, ll> pll;
typedef long double ld;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define popf pop_front
#define pf push_front
#define popb pop_back
#define mp make_pair
#define pb push_back
#define fi first
#define se second

// If the time limit is strict, try not to use long double

const double EPS = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const ll LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
// Do dir^1 to get reverse direction
const char dch[4] = {'R', 'L', 'D', 'U'};
// const string ds[8] = {"E","W","S","N","SE","NW","SW","NE"};
const double PI = 3.141592653589793;

inline void open(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}

inline void fasterios() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
}

// Remember to undefine if the problem is interactive
#define endl '\n'
const int MAXK = 2e6 + 5;
int par[MAXK];
int findpar(int pos) {
  if (par[pos] == pos) return pos;
  return par[pos] = findpar(par[pos]);
}
map <int, int> compressed;

int revCompressed[MAXK];
int safeIndex = 4e5 + 1;

int getCompressed(int x) {
  if (!compressed.count(x)) {
    compressed[x] = safeIndex;
    revCompressed[safeIndex] = x;
    safeIndex++;
  }
  return compressed[x];
}

int main() {
  fasterios();
  rep(i, 0, MAXK) par[i] = i;
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    LL x; cin >> x;
    int curidx = getCompressed(x);
    par[i] = curidx;
  }
  int q; cin >> q;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int i, v; cin >> i >> v;
      par[i] = getCompressed(v);
    } else if (t == 2) {
      int i; cin >> i;
      cout << revCompressed[findpar(i)] << endl;
    } else {
      int l, r;
      cin >> l >> r;
      PII curidx = {getCompressed(l - 1), getCompressed(r + 1)};
      for (auto it = compressed.lower_bound(l);;) {        
        if (it->fi > r) break;
        if (((r + 1) - (it->fi)) > ((it->fi) - (l - 1))) par[it->se] = curidx.fi;
        else par[it->se] = curidx.se;
        auto nx = next(it);
        compressed.erase(it);
        it = nx;
      }
    }
  }
}