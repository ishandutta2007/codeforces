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

const int N = 6e5+7;
V <ii> d[N];

ii tree[N << 2], best[N << 2];
void gap(int v, ii x) {
    ckmax(tree[v], x);
    ckmax(best[v], x);
}
void children(int v) {
    best[v] = max(best[v * 2 + 1], best[v * 2 + 2]);
}
void push(int v) {
    gap(v * 2 + 1, tree[v]);
    gap(v * 2 + 2, tree[v]);
}
ii getmax(int v, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) {
        return mp(-N, -N);
    }
    if (ql <= l && r <= qr) {
        return best[v];
    }
    int m = (l + r) / 2;
    push(v);
    return max(getmax(v * 2 + 1, l, m, ql, qr), getmax(v * 2 + 2, m + 1, r, ql, qr));
}
ii getmax(int l, int r) {
    return getmax(0, 0, N, l, r);
}
void relax(int v, int l, int r, int ql, int qr, ii x) {
    if (r < ql || qr < l) {
        return;
    }
    if (ql <= l && r <= qr) {
        gap(v, x);
        return;
    }
    int m = (l + r) / 2;
    push(v);
    relax(v * 2 + 1, l, m, ql, qr, x);
    relax(v * 2 + 2, m + 1, r, ql, qr, x);
    children(v);
}
void relax(int l, int r, ii x) {
    relax(0, 0, N, l, r, x);
} 

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    FOR (i, N << 2) {
        tree[i] = mp(-N, -N);
    }

    int n, m;
    cin >> n >> m;
    vi c;
    FOR (i, m) {
        int row, l, r;
        cin >> row >> l >> r;
        d[row].app(mp(l, r));
        c.app(l); c.app(r);
    }

    sort(all(c)); c.resize(unique(all(c)) - c.begin());

    vi dp(n + 1, 1);
    vi par(n + 1, -1);
    ii ans = mp(-1, -1);
    FORN (i, n) {
        each (seg, d[i]) {
            seg.x = lower_bound(all(c), seg.x) - c.begin();
            seg.y = lower_bound(all(c), seg.y) - c.begin();
        }
        each (seg, d[i]) {
            int l = seg.x, r = seg.y;
            auto t = getmax(l, r);
            t.x++;
            if (ckmax(dp[i], t.x)) {
                par[i] = t.y;
            }
        }
        each (seg, d[i]) {
            int l = seg.x, r = seg.y;
            relax(l, r, mp(dp[i], i));
        }
        ckmax(ans, mp(dp[i], i));
    }

    vi used(n + 1);
    int u = ans.y;
    while (u != -1) {
        used[u] = 1;
        u = par[u];
    }

    cout << n - ans.x << endl;
    FORN (i, n) {
        if (!used[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
}