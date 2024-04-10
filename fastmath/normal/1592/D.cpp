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

const int N = 1007;
bool used[N];
vi g[N];

set <ii> del;
vi ord;

void dfs(int u) {
    used[u] = 1;
    ord.app(u);
    each (v, g[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
}

signed main() {
    int n;
    cin >> n;
    V <ii> ed(n - 1);
    FOR (i, n - 1) {
        cin >> ed[i].x >> ed[i].y;
    }

    int mx = 0;
    cout << "? " << n << ' ';
    FORN (u, n) cout << u << ' ';
    cout << endl;
    cin >> mx;

    while (1) {
        int alive = 0;
        each (e, ed) {
            alive += !del.count(e);
        }
        assert(alive);
        if (alive==1) {
            each (e, ed) {
                if (!del.count(e)) {
                    cout << "! " << e.x << ' ' << e.y << endl;
                    exit(0);
                }
            }
        }
        FORN (u, n) {
            g[u].clear();
        }
        each (e, ed) {
            if (!del.count(e)) {
                g[e.x].app(e.y);
                g[e.y].app(e.x);
            }
        }

        int half = alive/2;

        int comp = 0;
        memset(used, 0, sizeof used);
        vi ask;
        FORN (u, n) {
            if (!used[u]) {
                ord.clear();
                dfs(u);
                comp++;
                if ((int)ask.size() + (int)ord.size() - comp >= half) {
                    int want = half + comp;
                    int add = want - (int)ask.size();
                    FOR (i, add) {
                        ask.app(ord[i]);
                    }
                    cout << "? " << ask.size() << ' ' << ask << endl;

                    int ans;
                    cin >> ans;

                    vi in_ask(n + 1);
                    each (e, ask) {
                        in_ask[e] = 1;
                    }

                    if (ans == mx) {
                        each (e, ed) {
                            if ((!in_ask[e.x]) || (!in_ask[e.y])) {
                                del.insert(e);
                                del.insert(mp(e.y, e.x));
                            }
                        }
                    }
                    else {
                        each (e, ed) {
                            if (in_ask[e.x] && in_ask[e.y]) {
                                del.insert(e);
                                del.insert(mp(e.y, e.x));
                            }
                        }
                    }
                    break;
                }
                else {
                    each (e, ord) {
                        ask.app(e);
                    }
                }
            }
        }
    }
}