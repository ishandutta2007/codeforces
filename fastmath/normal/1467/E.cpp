#include<bits/stdc++.h>
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
#define debug(x) std::cout << #x << ": " << x << '\n';
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
//ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
//ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
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

const int N = 2e5+7;

int n;
int a[N];
vi g[N];
int ptr = 1;
int l[N], r[N];
int par[N];
vi pos[N];

void dfs1(int u, int p) {
    par[u] = p;
    l[u] = ptr;
    pos[a[u]].app(ptr);
    ptr++;
    for (int v : g[u]) {
        if (v != p) {
            dfs1(v, u);
        }   
    }   
    r[u] = ptr - 1;
}   

int cnt[N];
int add[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    vi c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c.app(a[i]);
    }
    sort(all(c));
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(all(c), a[i]) - c.begin();
        cnt[a[i]]++;
    }
    FOR (i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    dfs1(1, 1);
    
    auto ban = [&] (int l, int r) {
        if (l <= r) {
            add[l]++;
            add[r + 1]--;
        }
    };  

    auto countx = [&] (vi &a, int l, int r) {
        return upper_bound(all(a), r) - lower_bound(all(a), l);
    };  

    for (int u = 1; u <= n; ++u) {
        int x = a[u];
        if (cnt[x] > 1) {
            ban(l[u], l[u]);
            trav (v, g[u]) {
                if (v != par[u]) {
                    if (countx(pos[x], l[v], r[v]) != cnt[x] - 1) {
                        ban(l[v], r[v]);
                    }       
                }
            }   
            if (u != 1) {
                if (countx(pos[x], l[u], r[u]) > 1) {
                    ban(1, l[u] - 1);
                    ban(r[u] + 1, n);
                }   
            }   
        }   
    }   

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        add[i] += add[i - 1];
        ans += !add[i];
    }   
    cout << ans << endl;
}