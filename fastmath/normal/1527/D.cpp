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

const int N = 2e5+7;
const int LG = 20;
vi g[N];
int ptr = 0, to[N][LG], h[N], l[N], r[N], cnt[N];
void calc(int u, int p) {
    to[u][0] = p;
    for (int i = 1; i < LG; ++i)
        to[u][i] = to[to[u][i-1]][i-1];
    l[u] = ptr;
    ptr++;    
    cnt[u] = 1;
    for (int v : g[u])  
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u);
            cnt[u] += cnt[v];
        }
   r[u] = ptr - 1;
}   
bool anc(int u, int v) { return l[u] <= l[v] && r[v] <= r[u]; }
int lca(int u, int v) {
    if (anc(u,v))   
        return u;
    for (int i = LG - 1; i >= 0; --i)
        if (!anc(to[u][i], v))
            u = to[u][i];
    return to[u][0];
}   
int pre(int u, int v) {
    if (anc(u,v))   
        assert(0);
    for (int i = LG - 1; i >= 0; --i)
        if (!anc(to[u][i], v))
            u = to[u][i];
    return u;
} 
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ptr = 0;
        FOR (i, n) {
            h[i] = l[i] = r[i] = 0;
            g[i].clear();
        }
        FOR (i, n - 1) {
            int u, v;
            cin >> u >> v;
            g[u].app(v); g[v].app(u);
        }
        calc(0, 0);

        vi ans(n + 2);
        ans[0] = n * (n - 1) / 2;

        auto get = [&] (int u, int v) {
            if (h[u] < h[v]) {
                swap(u, v);
            }
            int l = lca(u, v);
            if (l == v) {
                int up = n - cnt[pre(u, v)];
                int down = cnt[u];
                return up * down;
            }
            else {
                return cnt[u] * cnt[v];
            }
        };

        ans[1] = ans[0];
        trav (v, g[0]) {
            ans[1] -= cnt[v] * (cnt[v] - 1) / 2;
        }

        int u = 0, v = 1;
        ans[2] = get(0, 1);
        for (int i = 2; i < n; ++i) {
            if (h[u] < h[v]) {
                swap(u, v);
            }
            int l = lca(u, v);
            if (anc(l, i) && anc(i, u)) {

            }
            else if (anc(l, i) && anc(i, v)) {

            }
            else {

                if (l == v) {
                    int p = pre(u, v);
                    if (anc(u, i)) {
                        u = i;
                    }
                    else if (anc(p, i)) {
                        break;
                    }
                    else {
                        v = i;
                    }
                }
                else {
                    if (anc(u, i) && !anc(v, i)) {
                        u = i;
                    }
                    else if (anc(v, i) && !anc(u, i)) {
                        v = i;
                    }
                    else {
                        break;
                    }                    
                }
            }

            ans[i + 1] = get(u, v);
        }

        /*
        debug(ans[1]);
        debug(ans[2]);
        debug(ans[3]);
        */

        FOR (i, n + 1) {
            cout << ans[i] - ans[i + 1] << ' ';
        }
        cout << endl;
    }
}