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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FORN(i, n) for (int i = 1; i <= n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
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
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
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

const int MOD = 998244353;

const int N = 57, C = 26, LG = 30;
int ptr = 1;
int par[N], len[N], trie[N][C], last[N];
bool term[N];
int term_link[N];

const int S = 250;
int dp[LG][S][S];
int cur[S], nu[S];

int go[N][N][N][N];

bool used[N][N];
void dfs(int u, int v) {
    used[u][v] = 1;
    FOR (uu, N) {
        FOR (vv, N) {
            if (go[u][v][uu][vv] && !used[uu][vv]) {
                dfs(uu, vv);
            }
        }
    }
}

int sz = 0;
int num[N][N];

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
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
    trav (s, a) {
        int u = 0;
        trav (c, s) {
            if (!trie[u][c - 'a']) {
                trie[u][c - 'a'] = ptr;
                len[ptr] = len[u] + 1;
                par[ptr] = u;
                last[ptr] = c - 'a';
                ptr++;
            }
            u = trie[u][c - 'a'];
        }
        term[u] = 1;
    }

    FOR (u, ptr) {
        FOR (v, ptr) {
            FOR (c, C) {
                if (trie[u][c] && trie[v][c]) {
                    int uu = trie[u][c];
                    int vv = trie[v][c];
                    go[u][v][uu][vv]++;
                    if (term[uu]) {
                        go[u][v][0][vv]++;
                    }
                    if (term[vv]) {
                        go[u][v][uu][0]++;
                    }
                    if (term[uu] && term[vv]) {
                        go[u][v][0][0]++;
                    }
                }
            }
        }
    }

    dfs(0, 0);

    FOR (u, ptr) {
        FOR (v, ptr) {
            if (used[u][v]) {
                num[u][v] = sz;
                sz++;
            }
        }
    }

    assert(sz < S);

    FOR (u, ptr) {
        FOR (v, ptr) {
            if (used[u][v]) {
                FOR (uu, ptr) {
                    FOR (vv, ptr) {
                        if (used[uu][vv]) {
                            dp[0][num[u][v]][num[uu][vv]] = go[u][v][uu][vv];
                        }   
                    }
                }
            }
        }
    }

    FORN (t, LG - 1) {
        FOR (u, sz) {
            FOR (v, sz) {
                FOR (k, sz) {
                    add(dp[t][u][v], dp[t - 1][u][k] * dp[t - 1][k][v] % MOD);
                }
            }
        }
    }

    cur[0] = 1;
    FOR (p, LG) {
        if ((m >> p) & 1) {
            FOR (i, sz) {
                nu[i] = 0;
            }
            FOR (i, sz) {
                FOR (j, sz) {
                    add(nu[j], cur[i] * dp[p][i][j] % MOD);
                }
            }
            FOR (i, sz) {
                cur[i] = nu[i];
            }
        }
    }
    cout << cur[0] << endl;
}