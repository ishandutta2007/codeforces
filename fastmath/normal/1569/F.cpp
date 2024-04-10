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

const int N = 12;

int n, m, k;
set <set <int> > dp[1 << N][N][N];
bool g[N][N];

ll ans = 0;
//ll fac[N + 1], C[N + 1][N + 1];

set <set <int> > tot;

bool used[N];
int color[N];

ll A(int n, int k) {
    ll ans = 1;
    assert(k <= n);
    FOR (i, k) {
        ans *= n - i;
    }
    return ans;
}

bool paired[N];
set <int> cur;
bool gen_pairing(int i) {
    if (i == n) {
        if (tot.count(cur)) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if (paired[i]) {
        if (gen_pairing(i + 1)) {
            return 1;
        }
    }
    else {
        for (int j = i + 1; j < n; ++j) {
            if (!paired[j] && color[i] == color[j]) {
                paired[i] = paired[j] = 1;
                cur.insert(i * n + j);
                bool ans = gen_pairing(i + 1);
                paired[i] = paired[j] = 0;
                cur.erase(i * n + j);
                if (ans) return 1;
            }
        }
    }
    return 0;
}

int part = 0;

//warning! recursion!
void gen(int c) {
    int mn = n;
    FOR (i, n) {
        if (!used[i]) {
            ckmin(mn, i);
        }
    }
    if (mn == n) {
        part++;
        if (gen_pairing(0) && c <= k) {
            ans += A(k, c);
        }
        return;
    }

    int alive = (1 << n) - 1;
    FOR (i, n) {
        if (used[i]) {
            alive ^= 1 << i;
        }
    }

    for (int mask = alive; mask; mask = (mask - 1) & alive) {
        if (Bit(mask, mn) && (bp(mask)%2==0)) {
            FOR (i, n) {
                if (Bit(mask, i)) {
                    used[i] = 1;
                    color[i] = c;
                }
            }
            gen(c + 1);
            FOR (i, n) {
                if (Bit(mask, i)) {
                    used[i] = 0;
                    color[i] = -1;
                }
            }
        }
    }
}

signed main() {
    #ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    /*
    fac[0] = 1;
    FORN (i, N) {
        fac[i] = fac[i - 1] * i;
    }

    FOR (i, N + 1) {
        C[i][0] = 1;
    }
    FORN (i, N) {
        FORN (j, N) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    */

    cin >> n >> m >> k;
    FOR (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = g[v][u] = 1;
    }

    FOR (r, n) {
        FOR (l, r) {
            if (g[l][r]) {
                dp[(1 << l) ^ (1 << r)][l][r].insert({l * n + r});
            }
        }
    }

    for (int sz = 2; sz < n; sz += 2) {
        FOR (mask, 1 << n) {
            if (bp(mask) == sz) {
                FOR (r, n) {
                    FOR (l, r) {
                        each (se, dp[mask][l][r]) {
                            FOR (r_go, n) {
                                if (!Bit(mask, r_go) && g[r][r_go]) {
                                    FOR (l_go, n) {
                                        if (!Bit(mask, l_go) && g[l][l_go]) {
                                            int mn = min(l_go, r_go);
                                            int mx = max(l_go, r_go);
                                            auto neu = se; neu.insert(mn * n + mx);
                                            dp[mask ^ (1 << mn) ^ (1 << mx)][mn][mx].insert(neu);
                                        }
                                    }
                                }
                            }
                        }
                        dp[mask][l][r].clear();
                    }
                }
            }
        }
    }

    debug("calc dp");
    debug(Time);

    FOR (r, n) {
        FOR (l, r) {
            each (se, dp[(1 << n)-1][l][r]) {
                tot.insert(se);
            }
        }
    }

    /*
    each (pairing, tot) {
        debug("pairing");
        each (pr, pairing) {
            debug(pr);
        }
    } 
    */

    gen(0);

    cout << ans << endl;

    debug(Time);
    debug(part);
}