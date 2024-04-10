#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
int n, m;
const int mod = 998244353;
vector<pair<int, int> > g[N];
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
namespace C{
    const int mod = 998244353;
    vector<int>a, nia;
    void pre(int n){
        a = vector<int>(n + 1, 1);
        nia = vector<int>(n + 1, 1);
        for (int i = 2; i <= n; i ++)
            a[i] = mul(a[i - 1] , i);
        nia[n] = calc(a[n], mod - 2);
        for (int i = n - 1; i >= 2; i --)
            nia[i] = mul(nia[i + 1] , (i + 1));
    }
    int C(int x, int y) {
        if (x < y || y < 0) return 0;
        return mul(mul(a[x], nia[y]), nia[x - y]);
    }
}
int sum;
int bz[N];
bool bz1[N];
int cnt = 0;
int a[20][2];
vector<pair<int, int> > e[N];
int e_mask[N];
int f[1<<20][41], tmp[41];
int w[1<<21][22];
int id[N];
int a_mask;
vector<int> d;
void dfs(int x) {
    if (bz1[x]) return;
    bz1[x] = 1;
    id[x] = d.size();
    d.push_back(x);
    for (auto u:e[x]) {
        a_mask |= (1 << u.second);
        dfs(u.first);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    C::pre(n);
    for (int i = 1 ; i <= n; i ++) {
        int l, r;
        scanf("%d %d", &l, &r);
        g[l].push_back({i, 1});
        g[r + 1].push_back({i, -1});
    }
    for (int i = 0; i < m; i ++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        bz[a[i][0]] = 1;
        bz[a[i][1]] = 1;
        e[a[i][0]].push_back({a[i][1], i});
        e[a[i][1]].push_back({a[i][0], i});
    }
    f[0][0] = 1;
    int mask = 0;
    vector<int> dd;
    for (int i = 0; i < m;i ++)
        if (!bz1[a[i][0]]){
            a_mask = 0;
            d.clear();
            dfs(a[i][0]);
            for (auto u:d) {
                for (auto v:e[u])
                    e_mask[u] |= (1 << id[v.first]);
                dd.push_back(u);
            }
            for (int i = 0; i < (1 << d.size()); i ++)
                for (int j = 0; j <= d.size(); j ++) w[i][j] = 0;
            w[0][0] = 1;
            for (int j = 0; j < d.size(); j ++)
                for (int k = 0; k < (1 << j); k ++)
                    if (!(e_mask[d[j]] & k))
                        w[k | (1 << j)][__builtin_popcount(k | (1 << j))] = w[k][__builtin_popcount(k)];
            for (int j = 0; j < d.size(); j ++)
                for (int k = 0; k < (1 << d.size()); k ++)
                    if (k & (1 << j)) {
                        for (int l = 0; l <= d.size(); l ++)
                            w[k][l] = add(w[k][l], w[k ^ (1 << j)][l]);
                    }
             for (int j = a_mask; j; j = ((j - 1) & a_mask))
             {
                 int can = 0;
                 for (int k = 0; k < m; k ++)
                     if ((j >> k) & 1)
                         can |= ((1 << id[a[k][0]])|(1 << id[a[k][1]]));
                 for (int k = mask; k ; k = ((k - 1) & mask))
                     for (int l = 0; l <= 40; l ++)
                         if (f[k][l])
                             for (int r = 0; r <= d.size(); r ++)
                                 f[k | j][l + r] = add(f[k | j][l + r], mul(f[k][l], w[can][r]));
                 for (int k = 0; k <= d.size(); k ++)
                     f[j][k] = w[can][k];
             }
             mask |= a_mask;
        }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (auto u:g[i])
            if (!bz[u.first])
                sum += u.second;
            else {
                bz1[u.first] = (u.second == -1);
            }
        int mask = 0, num = 0;
        for (int j = 0; j <= m * 2; j ++) tmp[j] = 0;
        for (int i = 0; i < m; i ++)
            if (!bz1[a[i][0]] && !bz1[a[i][1]])
                mask |= (1 << i);
        for (auto u:dd)
            if (!bz1[u]) {
                bool tag = 1;
                for (auto v:e[u])
                    if (!bz1[v.first])
                        tag = 0;
                num += tag;
            }
        for (int j = 0; j <= m * 2; j ++)
            if (f[mask][j])
                for (int i = 0; i <= num; i ++)
                    tmp[j + i] = add(tmp[j + i], mul(f[mask][j], C::C(num, i)));
        for (int j = 0; j <= 2 * m; j ++)
            ans = add(ans, mul(C::C(sum, i - j), tmp[j]));
    }
    printf("%d\n", ans);
    return 0;
}