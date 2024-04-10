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
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    auto IsPw = [&] (int n) {
        return (n & (n - 1)) == 0;
    };
    rep (t) {
        int n;
        cin >> n;
        V <vi> g(1 << n), lf(1 << n); //lf[i] - all smaller values adjacent to this vertex
        rep (n * (1 << (n - 1))) {
            int u, v;
            cin >> u >> v;
            g[u].app(v); g[v].app(u);
        }
        FOR (i, 1 << n) {
            sort(all(g[i]));
        }
        vi who(1 << n), val(1 << n, 1 << n);
        val[0] = 0;
        FOR (i, n) {
            who[1 << i] = g[0][i];
            val[g[0][i]] = 1 << i;
        }
        FOR (i, 1 << n) {
            if (i && !IsPw(i)) {
                vi want;
                int nei = -1;
                FOR (bit, n) {
                    if (Bit(i, bit)) {
                        nei = who[i ^ (1 << bit)];
                        want.app(i ^ (1 << bit));
                    }
                }
                reverse(all(want));
                each (v, g[nei]) {
                    if (lf[v] == want) {
                        who[i] = v;
                        val[v] = i;
                        break;
                    }
                }
            }
            each (v, g[who[i]]) {
                if (i < val[v]) {
                    lf[v].app(i);
                }
            }
        }
        cout << who << endl;
        if (IsPw(n)) {
            each (e, val) {
                int color = 0;
                FOR (bit, n) {
                    if (Bit(e, bit)) {
                        color ^= bit;
                    }
                }
                cout << color << ' ';
            }
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}