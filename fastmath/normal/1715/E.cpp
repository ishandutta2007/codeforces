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
struct Line {
    ll k, b;
 
    Line() : k(), b() {}
    Line (ll _k, ll _b) : k(_k), b(_b) {}
 
    ll getVal(ll x) {
        return k * x + b;
    }
};
struct Hull {
    vector<Line> lines;
    vector<ll> borders;
 
    Hull() : lines(), borders() {}
 
    void addLine(Line L) {
        while(!lines.empty()) {
            if (lines.back().getVal(borders.back()) >= L.getVal(borders.back())) {
                lines.pop_back();
                borders.pop_back();
            } else break;
        }
        if (lines.empty()) {
            lines.push_back(L);
            borders.push_back(0LL); //leftmost query
            return;
        }
        if (lines.back().k <= L.k) return;
        assert(lines.back().k - L.k >= 0);
        ll x = div_up(L.b - lines.back().b, lines.back().k - L.k); //must work for negative!
        lines.push_back(L);
        borders.push_back(x);
    }
    ll getMinVal(ll x) {
        int pos = upper_bound(borders.begin(), borders.end(), x) - borders.begin();
        if (pos == 0) throw;
        pos--;
        return lines[pos].getVal(x);
    }
};
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    V <V <ii> > g(n + 1);
    rep (m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].app({v, c});
        g[v].app({u, c});
    }
    auto dij = [&] (vi &dist) {
        priority_queue <ii, V <ii>, greater <ii> > q;
        FORN (u, n) {
            q.push(mp(dist[u], u));
        }
        while (q.size()) {
            auto [d, u] = q.top(); q.pop();
            if (d == dist[u]) {
                for (auto [v, c] : g[u]) {
                    if (ckmin(dist[v], dist[u] + c)) {
                        q.push(mp(dist[v], v));
                    }
                }
            }
        }
    };  
    vi dist(n + 1, 1e10);
    dist[1] = 0;
    rep (k) {
        dij(dist);
        vi nd = dist;

        {
        Hull h;
        FORN (u, n) {
            h.addLine(Line(-2*u, dist[u] + u * u));
            ckmin(nd[u], h.getMinVal(u) + u * u);
        }            
        }

        {
        Hull h;
        int rp = 0;
        for (int u = n; u; u--) {
            rp++;
            h.addLine(Line(-2*rp, dist[u] + rp * rp));
            ckmin(nd[u], h.getMinVal(rp) + rp * rp);
        }            
        }

        dist = nd;
    }
    dij(dist);
    FORN (u, n) {
        cout << dist[u] << ' ';
    }
    cout << endl;
}