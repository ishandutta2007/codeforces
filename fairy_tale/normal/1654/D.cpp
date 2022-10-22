
#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int,int> PI;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int add(int x,int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int a,int b) {
    LL r = 1LL * a * b;
    return r - r / mod * mod;
}

int powt(int a,int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

struct node {
    int v, x, y;
};
vector<node> g[maxn];
vector<PI> fac[maxn];
map<int, int> A, B, mx;
int inv[maxn];
int sum;

map<int, int> facp;
void fff(int x)
{
    facp.clear();
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int t = 0;
            while (x % i == 0) {
                t++;
                x /= i;
            }

            facp[i] = t;
        }
    }

    if (x > 1) facp[x] = 1;
}

void dfs(int u, int fa, int x)
{
    sum = add(sum, x);
    //cout << u << " == " << mul(x, 60)<<endl;
    for (auto e:g[u]) {
        if (e.v == fa) continue;

        vector<PI> &fenzi = fac[e.y];
        vector<PI> &fenmu = fac[e.x];
        vector<node> op;

        for (auto e1:fenzi) {
            if (B[e1.fi] <= e1.se) {
                e1.se -= B[e1.fi];
                op.push_back(node{1, e1.fi, B[e1.fi]});
                B[e1.fi] = 0;

                op.push_back(node{0, e1.fi, -e1.se});
                A[e1.fi] += e1.se;
            } else {
                op.push_back(node{1, e1.fi, e1.se});
                B[e1.fi] -= e1.se;
            }
        }

        for (auto e1:fenmu) {
            if (A[e1.fi] <= e1.se) {
                e1.se -= A[e1.fi];
                op.push_back(node{0, e1.fi, A[e1.fi]});
                A[e1.fi] = 0;

                op.push_back(node{1, e1.fi, -e1.se});
                B[e1.fi] += e1.se;
                mx[e1.fi] = max(mx[e1.fi], B[e1.fi]);
            } else {
                op.push_back(node{0, e1.fi, e1.se});
                A[e1.fi] -= e1.se;
            }
        }

        int w = mul(mul(x, e.y), inv[e.x]);
        dfs(e.v, u, w);

        for (auto e2:op) {
            if (e2.v == 0) {
                A[e2.x] += e2.y;
            } else {
                B[e2.x] += e2.y;
            }
        }
    }
}

void solve()
{
    int n;
    int u, v, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> x >> y;

        int gg = __gcd(x, y);
        x /= gg;
        y /= gg;

        g[u].push_back(node{v, x, y});
        g[v].push_back(node{u, y, x});
    }

    A.clear();
    B.clear();
    mx.clear();
    sum = 0;
    dfs(1, 0, 1);

    x = 1;
    for (auto e:mx) x = mul(x, powt(e.fi, e.se));
    //cout << "?? " << x<< endl;
    cout << mul(sum, x) << endl;
}



int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    inv[0] = inv[1] = 1;
    for (int i = 2; i < maxn; i++) inv[i] = mul(mod - mod / i, inv[mod % i]);

    for (int i = 2; i < maxn; i++) {
        fff(i);
        for (auto e:facp) {
            fac[i].push_back(PI(e.fi, e.se));
        }
    }

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}