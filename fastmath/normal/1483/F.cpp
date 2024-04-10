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
#define FOR(i, n) for (int i = 0; i < n; ++i)
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
const int N = 1e6+7, C = 26;
int ptr = 1;
int par[N], link[N], len[N], trie[N][C], au[N][C], last[N];
bool term[N];
int term_link[N];

vi tree[N];

const int LG = 20;
int tree_ptr = 0, to[N][LG], h[N], l[N], r[N];
void calc(int u, int p) {
    to[u][0] = p;
    for (int i = 1; i < LG; ++i)
        to[u][i] = to[to[u][i-1]][i-1];
    l[u] = tree_ptr;
    tree_ptr++;    
    for (int v : tree[u])  
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u);
        }
   r[u] = tree_ptr - 1;
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
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }

int f[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
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
    queue <int> q;
    q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();

        if (len[u] > 1) {
            link[u] = au[link[par[u]]][last[u]];
        }

        if (term[u])
            term_link[u] = u;
        else
            term_link[u] = term_link[link[u]];

        FOR (c, C) {
            if (trie[u][c]) {
                au[u][c] = trie[u][c];
            }
            else if (u) {
                au[u][c] = au[link[u]][c];
            }
        }
        FOR (c, C) {
            if (trie[u][c]) {
                q.push(trie[u][c]);
            }
        }
    }
    for (int u = 1; u < ptr; ++u) {
        tree[link[u]].app(u);
    }
    calc(0, 0);
    int ans = 0;

    FOR (i, n) {
        f[i] = -1;
    }

    trav (s, a) {
        int u = 0;
        vi cand;
        int L = s.size();
        vi ln(L), vert(L);
        int i = 0, cur = 0;
        trav (c, s) {
            u = au[u][c - 'a'];
            cur++;
            if (cur == s.size()) {
                if (term_link[link[u]]) {
                    vert[i] = term_link[link[u]];
                    cand.app(vert[i]);
                    ln[i] = len[term_link[link[u]]];
                }
            }
            else {
                if (term_link[u]) {
                    vert[i] = term_link[u];
                    cand.app(vert[i]);
                    ln[i] = len[term_link[u]];
                }                
            }
            i++;
        }

        vi ban;
        int lf = N;
        for (int i = L - 1; i >= 0; --i) {
            if (i - ln[i] + 1 < lf) {
                lf = i - ln[i] + 1;
                ban.app(link[vert[i]]);
            }
            else {
                ban.app(vert[i]);
            }
        }

        sort(all(cand));
        cand.resize(unique(all(cand)) - cand.begin());
        auto comp = [&] (int u, int v) {
            return l[u] > l[v];
        };
        sort(all(cand), comp);
        sort(all(ban), comp);
        int minr = N;
        int ptr = 0;
        trav (u, cand) {
            while (ptr < ban.size() && l[u] <= l[ban[ptr]]) {
                ckmin(minr, r[ban[ptr]]);
                ptr++;
            }
            if (r[u] < minr) {
                ans++;
                minr = r[u];
            }
        }
    }
    cout << ans << endl;
}