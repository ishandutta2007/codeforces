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

const int N = 5e5+7;
int a[3][N], p[3][N];

const int INF = 2e18; //need long long for INF

struct Rmq {
    
    vi rmq;
    int sz;
    Rmq() {}
    Rmq(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        rmq.assign(sz * 2, -INF);
    }
    void put(int i, int x) {
        i += sz;
        ckmax(rmq[i], x);//rmq[i] += x;
        for (i /= 2; i; i /= 2) {
            rmq[i] = max(rmq[i*2], rmq[i*2+1]);
        }
    }
    void set(int i, int x) {
        i += sz;
        rmq[i] = x;//rmq[i] += x;
        for (i /= 2; i; i /= 2) {
            rmq[i] = max(rmq[i*2], rmq[i*2+1]);
        }
    }
    int get(int l, int r) {
        l += sz;
        r += sz;
        int res = -INF;
        while (l < r) {
            if (l%2 == 1) res = max(res, rmq[l]);
            if (r%2 == 0) res = max(res, rmq[r]);
            l = (l+1)/2;
            r = (r-1)/2;
        }
        if (l == r) res = max(res, rmq[l]);
        return res;
    }
};

int l[N], r[N];

int maxpref[N], maxsuf[N];

int ans = -INF;

Rmq tu(N), td(N);

void solve(int L, int R, V <array <int, 3> > seg) {
    if (L == R) {
        int mx = -INF;
        each (e, seg) ckmax(mx, -e[2]);
        ckmax(mx, maxpref[L]);
        ckmax(mx, maxsuf[L]);
        ckmax(ans, l[L] + r[L] + mx);
        /*
        if (ans == 9) {
            debug(maxpref[L]);
            debug(maxsuf[L]);
            debug(L);
            debug(l[L]);
            debug(r[L]);
            debug(mx);
            exit(0);
        }
    */
        return;
    }

    for (int i = R - 1; i >= L; --i) {
        ckmax(maxpref[i], maxpref[i + 1]);
    }
    for (int i = L + 1; i <= R; ++i) {
        ckmax(maxsuf[i], maxsuf[i - 1]);
    }

    int M = (L + R) / 2;
    for (int i = L; i <= R; ++i) {
        td.put(i, max(tu.get(L, min(i, M)), td.get(L - 1, i)) + maxpref[i]);
    }
    each (e, seg) {
        td.put(e[1], max(tu.get(e[0], min(e[1], M)), td.get(e[0] - 1, e[1])) - e[2]);
    }
    for (int i = L; i <= R; ++i) {
        td.put(R, max(tu.get(i, min(R, M)), td.get(i - 1, R)) + maxsuf[i]);
    }
    for (int i = M + 1; i <= R; ++i) {
        ckmax(ans, td.get(i, R) + r[i]);
    }
    for (int i = L; i <= R; ++i) {
        td.set(i, -INF);
    }

    V <array <int, 3> > segl, segr;
    each (e, seg) {
        if (e[1] <= M) {
            segl.app(e);
        }
        else if (e[0] > M) {
            segr.app(e);
        }
        else {
            ckmax(maxsuf[e[0]], -e[2]);
            ckmax(maxpref[e[1]], -e[2]);
        }
    }

    solve(L, M, segl);
    solve(M + 1, R, segr);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    FOR (i, 3) {
        FORN (j, n) {
            cin >> a[i][j];
            p[i][j] = p[i][j - 1] + a[i][j];
        }
    }
    FOR (i, N) {
        maxpref[i] = maxsuf[i] = -INF;
    }
    FORN (i, n) {
        l[i] = p[0][i] - p[1][i - 1];
        r[i] = p[2][n] - p[2][i - 1] + p[1][i];
    }
    FORN (i, n) {
        tu.put(i, l[i]);
    }
    V <array <int, 3> > seg(q);
    FOR (i, q) FOR (j, 3) cin >> seg[i][j];
    sort(all(seg));
    solve(1, n, seg);
    cout << ans << endl;
}