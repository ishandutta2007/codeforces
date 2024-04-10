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
#define debug(x) std::cerr << #x << ": " << x << '\n';

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

const int N = 3e5+7, LG = 20;
int to[N][LG];
int par[N];
int a[N], c[N];
int h[N];

int pre(int u, int p) {
    //debug(mp(u, p));
    assert(h[p] < h[u]);    
    int up = h[u] - h[p] - 1;
    FOR (i, LG) {
        if (Bit(up, i)) {
            u = to[u][i];
        }
    }
    return u;
}

signed main() {
    int q;
    cin >> q >> a[0] >> c[0];
    int ptr = 1;
    rep (q) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> par[ptr] >> a[ptr] >> c[ptr];
            h[ptr] = h[par[ptr]] + 1;

            //debug(ptr); debug(h[ptr]);

            to[ptr][0] = par[ptr];
            for (int i = 1; i < LG; ++i) {
                to[ptr][i] = to[to[ptr][i - 1]][i - 1];
            }
        }
        else {
            int v, w;
            cin >> v >> w;
            int u = v;
            for (int i = LG - 1; i >= 0; --i) {
                if (a[to[u][i]] > 0) {
                    u = to[u][i];
                }
            }

            int got = 0, cost = 0;

            while (1) {
                if (a[u] >= w) {
                    got += w;
                    cost += w * c[u];
                    a[u] -= w;
                    break;
                }
                else {
                    got += a[u];
                    cost += a[u] * c[u];
                    w -= a[u];
                    a[u] = 0;
                }
                if (u == v) {
                    break;
                }
                u = pre(v, u);
            }

            cout << got << ' ' << cost << endl;
        } 
        ptr++;  
    }
}