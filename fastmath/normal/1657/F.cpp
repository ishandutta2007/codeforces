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
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
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


int N;
vector < vector<int> > g, gt;
vector<bool> used;
vector<int> order, comp;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs1 (to);
    }
    order.push_back (v);
}

void dfs2 (int v, int cl) {
    comp[v] = cl;
    for (size_t i=0; i<gt[v].size(); ++i) {
        int to = gt[v][i];
        if (comp[to] == -1)
            dfs2 (to, cl);
    }
}

const int maxn = 4e5+7;
vi tree[maxn];

int ptr = 0, h[maxn], l[maxn], r[maxn], par[maxn], jump[maxn];
void calc(int u, int p) {
    par[u] = p;
    if (u == p) {
        jump[u] = u;
    }
    else if (h[p] - h[jump[p]] == h[jump[p]] - h[jump[jump[p]]]) {
        jump[u] = jump[jump[p]];
    }
    else {
        jump[u] = p;
    }
    l[u] = ptr;
    ptr++;    
    for (int v : tree[u]) {
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u);
        }
    }
    r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (anc(u, v)) { 
        return u;
    }
    while (!anc(par[u], v)) {
        if (!anc(jump[u], v)) {
            u = jump[u];
        }
        else {
            u = par[u];
        }
    }
    return par[u];
}   
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }

int st[maxn];

const int C = 26;

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    rep (n - 1) {
        int u, v;
        cin >> u >> v;
        tree[u].app(v); tree[v].app(u);
    }

    calc(1, 1);

    N = n * 2 + q * 2;
    g.resize(N);
    gt.resize(N);
    /*

    used.resize(N);
    comp.resize(N);
    */


    auto edge =[&] (int u, int v) {
        g[u].app(v);
        gt[v].app(u);
        g[v^1].app(u^1);
        gt[u^1].app(v^1);
    };

    debug("s");

    V <string> cand(n + 1);

    int ptr = 2 * n;

    debug("t");

    vi qust(q);
    vi U(q), V_(q);
    V <string> S(q);
    FOR (i, q) {
        int u, v;
        string s;
        cin >> u >> v >> s;

        U[i] = u; V_[i] = v; S[i] = s;

        vi le, ri;

        int l = lca(u, v);
        while (u != l) {
            le.app(u);
            u = par[u];
        }

        while (v != l) {
            ri.app(v);
            v = par[v];
        }
        reverse(all(ri));

        vi path =le;
        path.app(l);
        each (e, ri) {
            path.app(e);
        }

        auto in = [&] (char c, string s) {
            each (e, s) {
                if (c == e) {
                    return true;
                }
            }
            return false;
        };

        FOR (i, path.size()) {
            int u = path[i];
            char c1 = s[i];
            char c2 = s[(int)s.size() - 1 - i];
            if (cand[u].empty()) {
                if (c1 == c2) {
                    cand[u] += c1;
                }
                else {
                    cand[u] += c1;
                    cand[u] += c2;
                }
            }
            else {
                string nu;
                if (in(c1, cand[u])) {
                    nu += c1;
                }
                if (c1 != c2 && in(c2, cand[u])) {
                    nu += c2;
                }
                if (nu.empty()) {
                    cout << "NO" << endl;
                    exit(0);
                }
                cand[u] = nu;
            }
        }

        qust[i] = ptr;
    }

    FOR (i, q) {
        int u = U[i], v = V_[i];
        string s = S[i];

        vi le, ri;

        int l = lca(u, v);
        while (u != l) {
            le.app(u);
            u = par[u];
        }

        while (v != l) {
            ri.app(v);
            v = par[v];
        }
        reverse(all(ri));

        vi path =le;
        path.app(l);
        each (e, ri) {
            path.app(e);
        }

        qust[i] = ptr;
        assert(path.size() == s.size());
        FOR (i, path.size()) {
            int u = path[i];
            assert(cand[u].size());
            if (cand[u].size() == 1) {
                if (cand[u][0] != s[i]) {
                    edge(ptr, ptr + 1);
                }
            }
            else {
                if (s[i] == cand[u][0]) {
                    edge(ptr, (u - 1) * 2 + 0);
                }
                else {
                    edge(ptr, (u - 1) * 2 + 1);
                }
            }
        }
        reverse(all(path));
        FOR (i, path.size()) {
            int u = path[i];
            assert(cand[u].size());
            if (cand[u].size() == 1) {
                if (cand[u][0] != s[i]) {
                    edge(ptr + 1, ptr);
                }
            }
            else {
                if (s[i] == cand[u][0]) {
                    edge(ptr + 1, (u - 1) * 2 + 0);
                }
                else {
                    edge(ptr + 1, (u - 1) * 2 + 1);
                }
            }
        }

        ptr += 2;
    }

    debug("l");

    used.assign (N, false);
    for (int i=0; i<N; ++i)
        if (!used[i])
            dfs1 (i);

    comp.assign (N, -1);
    for (int i=0, j=0; i<N; ++i) {
        int v = order[N-i-1];
        if (comp[v] == -1)
            dfs2 (v, j++);
    }


    for (int i=0; i<N; ++i)
        if (comp[i] == comp[i^1]) {
            cout << "NO" << endl;
            return 0;
        }

    cout << "YES" << endl;
    FORN (u, n) {
        if (cand[u].empty()) {
            cout << 'a';
        }
        else if (cand[u].size() == 1) {
            cout << cand[u];
        }
        else {
            assert(cand[u].size() == 2);
            if (comp[(u - 1) * 2 + 0] > comp[(u - 1) * 2 + 1]) {
                cout << cand[u][0];
            }
            else {
                cout << cand[u][1];
            }
        }
    }

    /*
    for (int i=0; i<N; ++i) {
        int ans = comp[i] > comp[i^1] ? i : i^1;
        printf ("%d ", ans);
    }
    */
}