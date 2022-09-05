#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int maxn = 100010;
int n, P, rt, all, sz[maxn], mx[maxn], pw[maxn], ipw[maxn], dep[maxn];
bool solved[maxn];
vector<pair<int, int>> G[maxn];
__gnu_pbds::gp_hash_table<int, int> mp1, mp2;
vector<int> V1, V2;
long long ans;

void exgcd(int a, int b, int &x, int &y) {
    if (!b) { x = 1, y = 0; return; }
    exgcd(b, a % b, y, x), y -= a / b * x;
}

int inv(int a) {
    int x, y; exgcd(a, P, x, y);
    return (x + P) % P;
}

int main() {
    scanf("%d %d", &n, &P);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    for (int i = pw[0] = ipw[0] = 1; i <= n; i++) {
        pw[i] = 10LL * pw[i - 1] % P, ipw[i] = inv(pw[i]);
    }
    function<void(int, int)> find_rt = [&](int v, int fa) {
        sz[v] = 1, mx[v] = 0;
        for (auto e : G[v]) if (e.first ^ fa && !solved[e.first]) {
            find_rt(e.first, v);
            sz[v] += sz[e.first], mx[v] = max(mx[v], sz[e.first]);
        }
        mx[v] = max(mx[v], all - sz[v]);
        if (!~rt || mx[v] < mx[rt]) rt = v;
    };
    function<void(int)> solve = [&](int v) {
        mp1.clear(), mp2.clear(), dep[v] = 0;
        solved[v] = 1;
        for (auto e : G[v]) if (!solved[e.first]) {
            V1.clear(), V2.clear();
            function<void(int, int, int, int)> dfs = [&](int v, int fa, int v1, int v2) {
                dep[v] = dep[fa] + 1, sz[v] = 1;
                ans += !v1 + !v2;
                if (mp1.find(v2) != mp1.end()) ans += mp1[v2];
                int x = 1LL * (P - v1) * ipw[dep[v]] % P;
                if (mp2.find(x) != mp2.end()) ans += mp2[x];
                V1.push_back(x), V2.push_back(v2);
                for (auto u : G[v]) if (u.first ^ fa && !solved[u.first]) {
                    dfs(u.first, v, (10LL * v1 + u.second) % P, (v2 + 1LL * pw[dep[v]] * u.second) % P);
                    sz[v] += sz[u.first];
                }
            };
            dfs(e.first, v, e.second % P, e.second % P);
            for (int x : V1) mp1[x]++;
            for (int x : V2) mp2[x]++;
        }
        for (auto e : G[v]) if (!solved[e.first]) {
            rt = -1, all = sz[e.first];
            find_rt(e.first, v), solve(rt);
        }
    };
    solve(1), printf("%lld\n", ans);
    return 0;
}