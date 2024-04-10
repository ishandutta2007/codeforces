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

struct Rmq {
    const int INF = 2e18; //need long long for INF
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

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;

    V <string> a(n);
    cin >> a;

    V <vi> go(n, vi(m));
    FOR (c, m) {
        FOR (r, n) {
            go[r][c] = c;
            if (r == 0) {
                go[r][c] = -1;
            }
            else {
                if (a[r - 1][c]=='.') ckmin(go[r][c], go[r - 1][c]);
                if (c == 0) {
                    go[r][c] = -1;
                }
                else {
                    if (a[r][c - 1] == '.') ckmin(go[r][c], go[r][c - 1]);
                }
            }
        }
    }

    vi mx(m);
    FOR (i, m) {
        mx[i] = -1;
        FOR (j, n) {
            ckmax(mx[i], go[j][i]);
        }
    }

    //debug(mx);

    Rmq d(m);
    FOR (i, m) {
        d.put(i, mx[i]);
    }

    int q;
    cin >> q;
    rep (q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (d.get(l, r) <= l) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}