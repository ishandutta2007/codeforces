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
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
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
const int N = 2e5+7;
vi g[N], tree[N];
set <ii> del;

int par[N];
void dfs1(int u, int p) {
    trav (v, g[u]) {
        if (v != p) {
            dfs1(v, u);
            tree[u].app(v);
            par[v] = u;
        }
    }
}

int cnt[N];
vi comp;
void dfs2(int u) {
    cnt[u] = 1;
    comp.app(u);
    trav (v, tree[u]) {
        if (!del.count(mp(u, v))) {
            dfs2(v);
            cnt[u] += cnt[v];
        }
    }
}

const int LG = 30;
int f[LG];

void gg() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    f[0] = f[1] = 1;
    for (int i = 2; i < LG; ++i)
        f[i] = f[i - 1] + f[i - 2];

    int n;
    cin >> n;
    FOR (i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].app(v);
        g[v].app(u);
    }
    dfs1(1, 1);
    queue <int> q;
    q.push(1);
    while (q.size()) {
        int u = q.front(); q.pop();
        comp.clear();
        dfs2(u);
        if (cnt[u] == 1) {
            continue;
        }

        int p = -1;
        FOR (i, LG)
            if (f[i] == cnt[u]) {
                p = i;
            }
        if (p == -1) {
            gg();
        }

        bool did = 0;
        trav (v, comp) {
            if (v != u && (cnt[v] == f[p - 1] || cnt[v] == f[p - 2])) {
                del.insert(mp(par[v], v));
                q.push(u);
                q.push(v);
                did = 1;
                break;
            }
        }

        if (!did) {
            gg();
        }
    }
    cout << "YES" << endl;
}