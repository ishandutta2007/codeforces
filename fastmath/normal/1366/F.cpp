#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }

const int N = 2007, T = 10000, INF = 1e18;

vector <ii> g[N];
int dp1[N], dp2[N];

void rel(int &a, int b) { a = max(a, b); }
void add(int &a, int b) { a = mod(a + b); }

int inv2;
int sum(int n) {
    return mod(mod(n * (n + 1)) * inv2);
}   
int getsum(int s, int d, int k) {
    return mod(s*k + sum(k)*d);
}   

struct Line {
    ll k, b;
 
    Line() : k(), b() {}
    Line (ll _k, ll _b) : k(_k), b(_b) {}
 
    ll getVal(ll x) {

        if (abs(k) > 1000 * 1000) {
            cout << "t1" << endl;
            exit(0);
        }   
        if (abs(x) > 1000 * 1000 * 1000) {
            cout << "t2" << endl;
            exit(0);
        }   

        return k * x + b;
    }
};
struct Hull {
    vector<Line> lines;
    vector<ll> borders;
 
    Hull() : lines(), borders() {}
 
    void addLine(Line L) {
        while(!lines.empty()) {
            if (lines.back().getVal(borders.back()) >= L.getVal(borders.back())) {
                lines.pop_back();
                borders.pop_back();
            } else break;
        }
        if (lines.empty()) {
            lines.push_back(L);
            borders.push_back(0LL);
            return;
        }
        if (lines.back().k <= L.k) return;
        ll x = (L.b - lines.back().b + lines.back().k - L.k - 1) / (lines.back().k - L.k);
        lines.push_back(L);
        borders.push_back(x);
    }

    int who(ll x) {
        int pos = upper_bound(borders.begin(), borders.end(), x) - borders.begin();
        if (pos == 0) throw;
        pos--;
        return pos;
    }   

    ll getMinVal(ll x) {
        int pos = upper_bound(borders.begin(), borders.end(), x) - borders.begin();
        if (pos == 0) throw;
        pos--;
        return lines[pos].getVal(x);
    }
} d;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    inv2 = fp(2, MOD - 2);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].app(mp(v, w));
        g[v].app(mp(u, w));
    }   

    for (int i = 2; i <= n; ++i)
        dp1[i] = -INF;            

    int ans = 0;
    for (int len = 1; len <= T; ++len) {
        for (int i = 1; i <= n; ++i)
            dp2[i] = -INF;

        for (int u = 1; u <= n; ++u) {
            if (dp1[u] == -INF)
                continue;

            for (auto e : g[u]) {
                int v = e.f, c = e.s;
                dp2[v] = max(dp2[v], dp1[u] + c);
            }   
        }   

        for (int i = 1; i <= n; ++i)
            dp1[i] = dp2[i];            

        if (len <= q) {
            int mx = 0;
            for (int i = 1; i <= n; ++i)
                rel(mx, dp1[i]);
            add(ans, mx);
        }   
    }
    
    vector <Line> ar;
    for (int u = 1; u <= n; ++u) {
        if (dp1[u] == -INF)
            continue;
        int mx = 0;
        for (auto e : g[u]) {
            mx = max(mx, e.s);            
        }   
        ar.app(Line(-mx, -(dp1[u] - T * mx)));
    }   
    
    auto comp = [](Line a, Line b) {
        return a.k > b.k;
    };

    sort(all(ar), comp);

    for (auto e : ar) {
        d.addLine(e);
    }   

    if (T < q) {
        int ptr = T + 1;
        while (ptr <= q) {
            int l = ptr;
            int r = q + 1;
            while (l < r - 1) {
                int m = (l + r) >> 1;
                if (d.who(m) == d.who(l))
                    l = m;
                else
                    r = m;
            }

            auto ln = d.lines[d.who(l)];
            add(ans, -ln.b * (l - ptr + 1));
            add(ans, -mod(sum(l) - sum(ptr - 1)) * ln.k);
            ptr = r;
        }   
    }   
    cout << ans << endl;
}