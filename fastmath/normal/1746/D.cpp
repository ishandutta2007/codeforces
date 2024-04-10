#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

const int N = 2e5+7;
vi tree[N];
int ptr = 0, h[N], l[N], r[N], par[N], jump[N], s[N], mn[N], mx[N];
vi dp[N];
void calc(int u, int p) {
  debug(u);
    par[u] = p;
    if (u == p) {
        jump[u] = u;
    }
    else if (h[p] - h[jump[p]] == h[jump[p]] - h[jump[jump[p]]]) {
        jump[u] = jump[jump[p]];
    }
    else {
        jump[u] = p;
    }
    l[u] = ptr;
    ptr++;    

    int d = tree[u].size();
      dp[u].resize(mx[u] - mn[u] + 1);


    if (d == 0) {
      for (int i = mn[u]; i <= mx[u]; ++i) {
        dp[u][i - mn[u]] = i * s[u];
      }
    }
    else {

      int cmn = mn[u]/d;
      int cmx = mx[u]/d;
      if (mx[u]%d) {
        cmx++;
      }

      for (int v : tree[u]) {
          if (v != p) {
              h[v] = h[u]+1;
              mn[v] = cmn;
              mx[v] = cmx;
              calc(v, u);
          }
      }

      for (int i = mn[u]; i <= mx[u]; ++i) {
        int t = i/d;
        int up = i%d;
        dp[u][i - mn[u]] = s[u] * i;
        each (v, tree[u]) {
          dp[u][i - mn[u]] += dp[v][t-mn[v]];
        }
        if (up) {
          vi cand;
          each (v, tree[u]) {
            cand.app(dp[v][t + 1-mn[v]] - dp[v][t-mn[v]]);
          }
          sort(all(cand));
          reverse(all(cand));

          FOR (j, up) {
            dp[u][i - mn[u]] += cand[j];
          }
        }


        debug3(u, mn[u], mx[u]);
        debug(dp[u]);

      }      
    }

    debug(u);

    r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (anc(u, v)) { 
        return u;
    }
    while (!anc(par[u], v)) {
        if (!anc(jump[u], v)) {
            u = jump[u];
        }
        else {
            u = par[u];
        }
    }
    return par[u];
}   
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto solve = [&] () {
      int n, k;
      cin >> n >> k;
      FORN (u, n) {
        dp[u].clear();
        tree[u].clear();
      }
      for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        tree[p].app(i);
      }
      FORN (u, n) {
        cin >> s[u];
      }
      mn[1] = mx[1] = k;
      calc(1, 1);
      debug("out");
      cout << dp[1][0] << endl;
    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}