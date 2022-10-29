#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int N = 5001;
int n, a, b;
namespace hamilton_path_for_competition_map{
    vector<vector<bool> > edge;
    vector<int> d;
    bool expand(int x, int n) {
        d.resize(0);
        d.push_back(x);
        for (int i = 0; i < n; i ++)
            if (i != x) {
                if (edge[d[d.size() - 1]][i]) d.push_back(i);
                else {
                    int x = 0;
                    while (edge[d[x]][i])
                        x ++;
                    d.push_back(i);
                    rotate(d.begin() + x, d.end() - 1, d.end());
                }
            }
        if (d.size() == n) return 1;
        return 0;
    }
    vector<int> construct(vector<vector<bool> >_edge, int n) {
        edge = _edge;
        for (int i = 0; i < n; i ++)
            if (expand(i, n)) {
                return d;
            }
        d.resize(0);
        return d;
    }
}
typedef long long ll;
const int mod = 1e9 + 7;
ll calc(ll x, ll y){
    ll z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y /= 2;
    }
    return z;
}
namespace C{
    const int mod = 1e9+7;
    vector<int>a, nia;
    void pre(int n){
        a = vector<int>(n + 1, 1);
        nia = vector<int>(n + 1, 1);
        for (int i = 2; i <= n; i ++)
            a[i] = 1ll * a[i - 1] * i % mod;
        nia[n] = calc(a[n], mod - 2);
        for (int i = n - 1; i >= 2; i --)
            nia[i] = 1ll * nia[i + 1] * (i + 1) % mod;
    }
    ll C(ll x, ll y) {
        if (x < y || y < 0 || x < 0) return 0;
        return 1ll * a[x] * nia[y] % mod * nia[x - y] % mod;
    }
}
namespace count{//liriab
    const int mod = 1e9+7;
    int gao(vector<pair<int, int> > d, int a, int b) {
        C::pre(d.size());
        sort(d.begin(), d.end(), [](pair<int, int> a, pair<int, int>b) {
            return a.second > b.second;
        });
        int ans = 0;
        for (int i = 0; i < d.size(); i ++) {
            int sumequal = 0, sumbigger = 0, sumsmaller = 0;
            for (int j = 0; j < d.size(); j ++)
                if (j != i) {
                    if (d[j].first <= d[i].second && d[j].second >= d[i].second) {
                        if (d[j].second == d[i].second && j > i) {
                            sumsmaller ++;
                        } else sumequal++;
                    }else {
                        if (d[j].second < d[i].second)
                            sumsmaller ++;
                        else
                            sumbigger ++;
                    }
                }
            for (int j = 0; j <= sumequal; j ++) {
                int x = b - j - 1;
                if (sumbigger + j + 1 > a || x > sumbigger || x < 0) continue;
                ans = (ans + 1ll * C::C(sumbigger, x) * C::C(sumequal, j)) % mod;
            }
        }
        return ans;
    }
}
int id[N];
int fa[N], c[2000001];
vector<int>w[N];
int getfa(int x) {
    return fa[x] == x? x : fa[x] = getfa(fa[x]);
}
int main() {
    scanf("%d %d %d", &n, &a, &b);
    vector<vector<bool> > edge(n, vector<bool>(n));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n ; j ++) {
            char c;
            while ((c = getchar()) != '0' && c != '1');
            if (c =='1') edge[i][j] = 1;
        }
    }
    vector<int>d = hamilton_path_for_competition_map::construct(edge, n);
    for (int i = 0; i < d.size();  i ++)
        id[d[i]] = i, fa[i] = i;
    for (int u = 0; u < n ; u ++) {
        int tmp = u;
        for (int v = 0; v < n; v++)
            if (edge[d[u]][v]) {
                tmp = min(tmp, id[v]);
            }
        for (int i = tmp; i < u; i ++)
            if (getfa(d[i]) != d[u]) {
                fa[getfa(d[i])] = d[u];
            }
    }
    vector<vector<int> > g(n, vector<int>(0));
    for (int i = 0; i < n; i ++)
        g[getfa(i)].push_back(i);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        while (x --) {
            char c;
            while ((c = getchar()) != '0' && c != '1');
            w[i].push_back(c - '0');
        }
    }
    vector<int> dd(0);
    for (auto u:d)
        if (getfa(u) == u)
            dd.push_back(u);
    for (int i = 0; i < dd.size(); i ++) {
        int u = dd[i];
        int gcd = 0;
        for (auto v:g[u]) {
            int tmp = w[v].size();
            gcd = __gcd(tmp, gcd);
        }
        for (int i = 0; i < gcd; i++)
            c[i] = 0;
        for (auto v:g[u])
            for (int i = 0; i < w[v].size(); i++)
                if (w[v][i])
                    c[i % gcd] = 1;
        for (auto v:g[u])
            for (int i = 0; i < w[v].size(); i++)
                if (!w[v][i] && c[i % gcd])
                    w[v][i] = 2;
        if (i != (int)dd.size() - 1) {
            int v = dd[i + 1];
            int tmp = w[v].size();
            int gcd1 = __gcd(tmp, gcd);
            for (int i = 0; i < gcd1; i ++)
                for (int j = 0; j * gcd1 + i < gcd; j ++)
                    c[i] |= c[i + j * gcd1];
            for (int i = 0; i < w[v].size(); i ++)
                if (!w[v][i] && c[i % gcd1])
                    w[v][i] = 2;
        }
    }
    vector<pair<int, int> > f;
    for (int i = 0; i < n; i ++) {
        int l = 0, r = 0;
        for (auto u:w[i])
            if (u == 1) l ++, r ++;
            else
                if (u == 2) r ++;
        f.push_back(make_pair(l, r));
    }
    printf("%d\n",count::gao(f, a, b));
    return 0;
}