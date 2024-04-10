#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;
const int V = 32000000;
int T, tot, p[V], ans[10010];
ll f[200010];
map<ll, vector<pair<ll, int>>> mp;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1, y = 0; return; }
    exgcd(b, a % b, y, x), y -= a / b * x;
}

int main() {
    fill(p, p + V, 1);
    for (int i = 2; i < V; i++) {
        if (p[i]) p[++tot] = i;
        for (int j = 1; j <= tot && i * p[j] < V; j++) {
            p[i * p[j]] = 0;
            if (!(i % p[j])) break;
        }
    }
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        ll n, K; scanf("%lld %lld", &n, &K);
        if (K > 1) mp[K].emplace_back(n, i);
    }
    for (auto foo : mp) {
        ll K = foo.first;
        vector<ll> fact;
        for (int i = 1; i <= tot; i++) if (!(K % p[i])) {
            fact.push_back(p[i]);
            while (!(K % p[i])) K /= p[i];
        }
        if (K > 1) fact.push_back(K);
        sort(fact.begin(), fact.end());
        if (fact.size() == 1) {
            for (auto p : foo.second) {
                if (!(p.first % fact[0])) ans[p.second] = 1;
            }
        } else if (fact.size() == 2) {
            ll _x, _y; exgcd(fact[0], fact[1], _x, _y);
            for (auto p : foo.second) {
                i128 x = (i128)_x * p.first;
                i128 y = (i128)_y * p.first;
                if (x < 0) {
                    i128 z = (-x + fact[1] - 1) / fact[1];
                    if (y >= 0 && y / fact[0] >= z) ans[p.second] = 1;
                } else if (y < 0) {
                    i128 z = (-y + fact[0] - 1) / fact[0];
                    if (x >= 0 && x / fact[1] >= z) ans[p.second] = 1;
                } else {
                    ans[p.second] = 1;
                }
            }
        } else {
            fill(f, f + fact[0], LLONG_MAX);
            Q.emplace(f[0] = 0, 0);
            while (!Q.empty()) {
                auto p = Q.top(); Q.pop();
                if (p.first ^ f[p.second]) continue;
                for (ll x : fact) {
                    ll y = (p.second + x) % fact[0];
                    if (f[y] > p.first + x) Q.emplace(f[y] = p.first + x, y);
                }
            }
            for (auto p : foo.second) {
                if (f[p.first % fact[0]] <= p.first) ans[p.second] = 1;
            }
        }
    }
    for (int i = 1; i <= T; i++) {
        puts(ans[i] ? "YES" : "NO");
    }
    return 0;
}