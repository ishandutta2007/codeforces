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
#else
#define debug(x)
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

const int N = 1e6+7;
int n, q, a[N], p[N], ans[N], d[N];
vi tree[N];
int cnt[N], sub[N << 2];
vi who[N];
V <array <int, 3> > ask[N];

void upd(int v, int l, int r, int p) {
    if (l == r) {
        sub[v] = d[l];
        return;
    }
    int m = (l + r) / 2;
    if (p <= m) upd(v * 2 + 1, l, m, p);
    else upd(v * 2 + 2, m + 1, r, p);
    sub[v] = sub[v * 2 + 1] + sub[v * 2 + 2];
}
int get(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return sub[v];
    int m = (l + r) / 2;
    return get(v * 2 + 1, l, m, ql, qr) + get(v * 2 + 2, m + 1, r, ql, qr);
}
int descend(int v, int l, int r, int k) {
    if (l == r) return l;
    int m = (l + r) / 2;
    if (k <= sub[v * 2 + 1]) return descend(v * 2 + 1, l, m, k);
    else return descend(v * 2 + 2, m + 1, r, k - sub[v * 2 + 1]);
}

void dfs(int u) {
    int x = a[u];

    d[cnt[x]]--;
    upd(0, 0, n, cnt[x]);

    cnt[x]++;

    d[cnt[x]]++;
    who[cnt[x]].app(x);
    upd(0, 0, n, cnt[x]);

    each (e, ask[u]) {
        int l = e[0], k = e[1], num = e[2];
        int p = get(0, 0, n, 0, l - 1);

        if (sub[0] < p + k) {
            ans[num] = -1;
        }
        else {
            int skolko = descend(0, 0, n, p + k);   
            while (who[skolko].size()) {
                int x = who[skolko].back();
                if (cnt[x] == skolko) {
                    ans[num] = x;
                    break;
                }
                else {
                    who[skolko].pop_back();
                }
            }
        }
        
    }

    each (v, tree[u]) {
        dfs(v);
    }

    d[cnt[x]]--;
    upd(0, 0, n, cnt[x]);

    cnt[x]--;
    
    d[cnt[x]]++;
    who[cnt[x]].app(x);
    upd(0, 0, n, cnt[x]);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    rep (t) {
        cin >> n >> q;
        FOR (i, n << 2) {
            sub[i] = 0;
        }
        FOR (i, n + 1) {
            cnt[i] = 0;
            tree[i].clear();
            d[i] = 0;
            ask[i].clear();
        }
        FORN (i, n) {
            cin >> a[i];
        }
        for (int i = 2; i <= n; ++i) {
            cin >> p[i];
            tree[p[i]].app(i);
        }
        FOR (i, q) {
            int v, l, k;
            cin >> v >> l >> k;
            ask[v].app({l, k, i});
        }
        FORN (u, n) who[0].app(u);
        d[0] = n;
        upd(0, 0, n, 0);
        dfs(1);
        FOR (i, q) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}