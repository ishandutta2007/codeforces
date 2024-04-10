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

const int N = 4e5+7;
bool used[N];
vi ord;
vi g[N], rg[N];

void dfs1(int u) {
    used[u] = 1;
    each (v, g[u]) {
        if (!used[v]) {
            dfs1(v);
        }
    }
    ord.app(u);
}

int in[N], cmp[N];
void dfs2(int u, int c) {
    used[u] = 1;
    cmp[u] = c;
    each (v, rg[u]) {
        if (!used[v]) {
            dfs2(v, c);
        }
    }
}

vi rev_dag[N];
int x[N], l[N], r[N];

void dfs3(int u) {
    used[u] = 1;
    each (v, rev_dag[u]) {
        if (!used[v]) {
            dfs3(v);
        }
        ckmin(l[u], l[v]);
        ckmax(r[u], r[v]);
    }
}

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

    vi want(m);
    cin >> want;

    auto num = [&] (int i, int j) {
        return i * m + j;
    };

    V <vi> down(n, vi (m));
    FOR (j, m) {
        for (int i = n - 1; i >= 0; --i) {
            if (a[i][j] == '#') {
                down[i][j] = i;
            }
            else if (i == n - 1) {
                down[i][j] = n;
            }
            else {
                down[i][j] = down[i + 1][j];
            }
        }
    }

    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == '#') {
                if (i + 1 < n && down[i + 1][j] != n) {
                    int x = down[i + 1][j];
                    g[num(i, j)].app(num(x, j));
                }
                if (i && a[i - 1][j] == '#') {
                    g[num(i, j)].app(num(i - 1, j));
                }
                if (j && down[i][j - 1] != n) {
                    int x = down[i][j - 1];
                    g[num(i, j)].app(num(x, j - 1));
                }
                if (j + 1 < m && down[i][j + 1] != n) {
                    int x = down[i][j + 1];
                    g[num(i, j)].app(num(x, j + 1));
                }
            }
        }
    }

    FOR (u, N) {
        each (v, g[u]) {
            rg[v].app(u);
        }
    }

    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == '#') {
                int u = num(i, j);
                if (!used[u]) {
                    dfs1(u);
                }
            }
        }
    }

    reverse(all(ord));

    memset(used, 0, sizeof used);
    int comp = 0;
    each (u, ord) {
        if (!used[u]) {
            dfs2(u, comp);
            comp++;
        }
    }

    FOR (u, N) {
        each (v, g[u]) {
            int U = cmp[u];
            int V = cmp[v];
            if (U != V) {
                in[V]++;
                rev_dag[V].app(U);
            }
        }
    }    

    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == '#') {
                int u = num(i, j);
                x[cmp[u]] = j;
            }
        }
    }

    FOR (i, N) {
        l[i] = N;
        r[i] = -N;
    }

    vi is_ord;
    V <ii> ist_ord;
    FOR (i, comp) {
        if (in[i] == 0) {
            ist_ord.app(mp(x[i], i));
        }
    }

    sort(all(ist_ord));

    FOR (i, ist_ord.size()) {
        int compon = ist_ord[i].y;
        l[compon] = r[compon] = i;
    }

    memset(used, 0, sizeof used);
    FOR (i, comp) {
        if (!used[i]) {
            dfs3(i);
        }
        assert(l[i] != N);
    }

    V <ii> seg;

    FOR (j, m) {
        if (want[j]) {
            for (int i = n - 1; i >= 0; --i) {
                if (a[i][j] == '#') {
                    want[j]--;
                    if (want[j] == 0) {

                        int u = cmp[num(i, j)];
                        seg.app(mp(l[u], r[u]));

                    }
                }
            }            
        }

    }

    auto seg_comp = [&] (ii a, ii b) {
        return a.y < b.y;
    };

    sort(all(seg), seg_comp);
    int have = -1;
    int ans = 0;
    each (e, seg) {
        if (have < e.x) {
            have = e.y;
            ans++;
        }
    }
    cout << ans << endl;
}