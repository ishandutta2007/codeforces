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

namespace PathMax {
struct Dsu {
int n;
vector <int> par, cnt;
Dsu (int n_) {
    n = n_;
    par.resize(n + 1);
    cnt.resize(n + 1, 1);
    FOR (i, n + 1)
        par[i] = i;
}   
int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);                
}   
int get_cnt(int u) {
    return cnt[root(u)];
}   
bool merge(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
        return 0;
    par[u] = v;
    cnt[v] += cnt[u];
    return 1;
}
bool connected(int u, int v) {
    return root(u) == root(v);
}   
bool cut(int u, int v) {
    return root(u) != root(v);
}
};  
const int N = 2e5+7, INF = 1e9+7; // check INF!
const int LG = 20;
int ptr = 0, h[N], l[N], r[N], parE[N], jump[N], maxOnJump[N], par[N];
void calc(int u, int p, int up_edge, V <V <ii> > &g) {
    par[u] = p;
    if (u == p) {
        jump[u] = u;
        parE[u] = maxOnJump[u] = -1;
    }
    else if (h[p] - h[jump[p]] == h[jump[p]] - h[jump[jump[p]]]) {
        jump[u] = jump[jump[p]];
        parE[u] = maxOnJump[u] = up_edge;
        ckmax(maxOnJump[u], maxOnJump[p]);
        ckmax(maxOnJump[u], maxOnJump[jump[p]]);
    }
    else {
        jump[u] = p;
        parE[u] = maxOnJump[u] = up_edge;
    }
    l[u] = ptr;
    ptr++;    
    for (auto e : g[u]) {
        auto [v, c] = e;
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u, c, g);
        }
    }
    r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (anc(u,v))   
        return u;
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
int GetMaxVertical(int u, int p) {
    if (u == p) {
        return -INF;
    }
    int ans = -INF;
    while (u != p) {
        if (h[p] <= h[jump[u]]) {
            ckmax(ans, maxOnJump[u]);
            u = jump[u];
        }
        else {
            ckmax(ans, parE[u]);
            u = par[u];
        }
    }
    return ans;
}
int GetMax(int u, int v) {
    int l = lca(u, v);
    return max(GetMaxVertical(u, l), GetMaxVertical(v, l));
}  
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }
vi PathMax(int n, V <array <int, 3> > E, V <ii> Q) { // E : (u, v, c); Q : (u, v); 1-indexation
    auto comp = [&] (array <int, 3> a, array <int, 3> b) { return a[2] < b[2]; };
    sort(all(E), comp);
    Dsu d(n);
    V <V <ii> > g(n + 1);
    each (e, E) {
        int u = e[0], v = e[1], c = e[2];
        if (d.merge(u, v)) {
            g[u].app(mp(v, c));
            g[v].app(mp(u, c));
        }
    }
    ptr = 0;
    calc(1, 1, -INF, g);
    vi ans(Q.size());
    FOR (i, Q.size()) {
        ans[i] = GetMax(Q[i].x, Q[i].y);
    }
    return ans;
}
};

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    rep (t) {
        int n, m;
        cin >> n >> m;
        V <array <int, 3> > E(m);
        V <ii> Q;
        set <ii> d;
        FOR (i, m) {
            FOR (j, 3) {
                cin >> E[i][j];
            }
            Q.emplace_back(E[i][0], E[i][1]);
            d.insert(mp(E[i][0], E[i][1])); d.insert(mp(E[i][1], E[i][0]));
        }
        V <vi> cla(n + 1), com(n + 1);
        vi VertComp(n + 1), CompClass(n + 1);
        V <array <int, 3> > NewE;
        int cur_c = -1;
        FORN (i, n) {
            com[i] = {i};
            cla[i] = {i};
            VertComp[i] = CompClass[i] = i;
        }
        auto PourComp = [&] (int a, int b) { // pour (a to b) or (b to a)
            NewE.app({com[a][0], com[b][0], cur_c});
            //each (e, com[a]) VertComp[e] = b;
            bool swp = com[a].size() > com[b].size();
            if (swp) swap(a, b);
            each (e, com[a]) VertComp[e] = b;
            com[b].insert(com[b].end(), com[a].begin(), com[a].end());
            return b;
        };
        auto comp = [&] (array <int, 3> a, array <int, 3> b) { return a[2] < b[2]; };
        sort(all(E), comp);
        each (e, E) {
            int u = e[0], v = e[1];
            cur_c = e[2];
            int SmallClass = CompClass[VertComp[u]], BigClass = CompClass[VertComp[v]];
            if (SmallClass == BigClass) continue;
            vi pen;
            vi OneVert(cla[SmallClass].size(), -1);
            int num = 0;
            each (CompSmall, cla[SmallClass]) {
                assert(com[CompSmall].size());
                vi wantPour;
                each (rep, com[CompSmall]) {
                    vi NewClaBig;
                    each (CompBig, cla[BigClass]) {
                        bool Edge = 0;
                        assert(com[CompBig].size());
                        each (v, com[CompBig]) {
                            if (d.find(mp(rep, v)) == d.end()) {
                                wantPour.app(CompBig);
                                Edge = 1;
                                break;
                            }
                        }
                        if (!Edge) {
                            NewClaBig.app(CompBig);
                        }
                    }
                    cla[BigClass] = NewClaBig;
                    if (NewClaBig.empty()) break;
                }
                if (wantPour.size()) {
                    int res = wantPour[0];
                    for (int i = 1; i < wantPour.size(); ++i) {
                        res = PourComp(wantPour[i], res);
                    }
                    cla[BigClass].app(res);
                    OneVert[num] = com[res][0];
                }
                else {
                    pen.app(CompSmall);
                }
                num++;
            }
            FOR (i, cla[SmallClass].size()) {
                if (OneVert[i] != -1) {
                    int newCom = VertComp[OneVert[i]];
                    PourComp(cla[SmallClass][i], newCom);
                }
            }
            each (CompSmall, cla[SmallClass]) {
                CompClass[CompSmall] = BigClass;
            }
            each (e, pen) cla[BigClass].app(e);
            each (c, cla[BigClass]) {
                c = VertComp[com[c][0]];
            }
        }
        vi ans = PathMax::PathMax(n, NewE, Q);
        each (e, ans) {
            cout << e << ' ';
        }
        cout << endl;
    }
}