#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int N = 2001;
long long f[N];
vector<pair<int, pair<int,int> > > g[N];
int n, m, q;
const int mod = 1e9 + 7;
pair<long long, long long> d[N];
pair<int, int> c[N];
pair<int, int> edge[N];
long double x[N];
int tot;

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
long double calc(pair<long long, long long> a, pair<long long, long long> b) {
    return (long double)(b.second - a.second) / (a.first - b.first);
}

int main(){
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back({y,{z, i}});
        g[y].push_back({x,{z, i}});
        c[i] = {z, i};
        edge[i] = {x, y};
    }
    sort(c + 1, c + m + 1);
    for (int i = 1; i <= m; i ++)
    {

        for (int j = 1; j <= n; j ++)
            f[j] = -1e18;
        f[edge[c[i].second].first] = f[edge[c[i].second].second] = 0;
        priority_queue<pair<long long, int> > q;
        q.push({0, edge[c[i].second].first});
        q.push({0, edge[c[i].second].second});
        while (!q.empty()) {
            auto u = q.top();
            q.pop();
            if (u.first != f[u.second])
                continue;
            for (auto v:g[u.second])
                if (v.second.first <= c[i].first && v.second.first - c[i].first + u.first > f[v.first])
                    q.push({f[v.first] = v.second.first - c[i].first + u.first, v.first});
        }
        d[++tot] = {c[i].first, f[1]};
        if (tot > 1) {
            x[tot - 1] = calc(d[tot - 1], d[tot]);
        }
        while (tot > 1) {
            if (d[tot].first >= d[tot - 1].first && d[tot].second >= d[tot - 1].second){
                d[tot - 1] = d[tot];
                tot --;
                if (tot > 1) {
                    x[tot - 1] = calc(d[tot - 1], d[tot]);
                }
                continue;
            }
            if (d[tot].first == d[tot - 1].first && d[tot].second <= d[tot - 1].second) {
                tot --;
                continue;
            }
            if (tot == 2) {
                break;
            }
            if (x[tot - 1] <= x[tot - 2]) {
                d[tot - 1] = d[tot];
                tot --;
                if (tot > 1) {
                    x[tot - 1] = calc(d[tot - 1], d[tot]);
                }
                continue;
            }
            break;
        }
    }
    while (tot > 1 && x[tot - 1] >= q)
        tot --;
    x[tot] = q;
    x[0] = 1;
    int ans = 0;
    for (int i = 1; i <= tot; i ++) {
        int l = ceil(x[i - 1]), r = floor(x[i]), len = r -  l + 1;
        if (1ll * d[i].first * l + d[i].second == 1ll * d[i - 1].first * l + d[i - 1].second && i > 1) l ++, len --;
        if (!len) continue;
        ans = add(add(ans, mul(d[i].first % mod, 1ll * (l + r) * len / 2 % mod)), mul(len, d[i].second % mod));
    }
    printf("%d\n", (ans % mod + mod) % mod);
    return 0;
}