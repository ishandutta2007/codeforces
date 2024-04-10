#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ins[MN], outs[MN], sz;
vector<pair<ll, ll>> adj[MN];
priority_queue<pair<ll, ll>> pobi, rico;

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < m; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        ins[b] += c;
        outs[a] += c;
    }

    for(int i = 1; i <= n; i++) {
        if(ins[i] > outs[i]) rico.push({i, ins[i] - outs[i]});
        if(ins[i] < outs[i]) pobi.push({i, outs[i] - ins[i]});
    }

    while(!pobi.empty()) {
        auto r = rico.top(); rico.pop();
        auto p = pobi.top(); pobi.pop();

        sz++;
        adj[p.first].emplace_back(r.first, min(p.second, r.second));

        if(r.second < p.second) {
            p.second -= r.second;
            pobi.push(p);
        } else if(r.second > p.second) {
            r.second -= p.second;
            rico.push(r);
        }
    }

    printf("%lld\n", sz);
    for(int i = 1; i <= n; i++)
        for(auto jonson : adj[i])
            printf("%d %lld %lld\n", i, jonson.first, jonson.second);
    return 0;
}