#include <bits/stdc++.h>

#define MN 3003

using namespace std;
typedef long long ll;

ll n, m, ans = LLONG_MAX, x[MN], cont, idx[MN], used[MN], val[MN], mine[MN];
vector<pair<int, int> > votos[MN];

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x[i], &val[i]);

        votos[x[i]].emplace_back(val[i], i);
        if(x[i] == 1) {
            cont++;
            mine[i]++;
        }
    }

    for(int i = 1; i <= m; i++) {
        sort(votos[i].begin(), votos[i].end());
    }

    for(int sc = 0; sc <= n; sc++) {
        ll soma = 0, quant = cont;
        memset(idx, 0, sizeof idx);
        memset(used, 0, sizeof used);
        priority_queue<pair<int, int> > votes;

        for(int i = 0; i < n; i++) {
            votes.push({-val[i], i});
        }

        for(int i = 2; i <= m; i++) {
            while(votos[i].size() - idx[i] > sc) {
                soma += votos[i][idx[i]].first;
                quant++;
                used[votos[i][idx[i]].second] = 1;
                idx[i]++;
            }
        }

        while(quant <= sc && !votes.empty()) {
            ll v = -votes.top().first;
            int id = votes.top().second;
            votes.pop();
            if(used[id] || mine[id]) continue;
            soma += v;
            quant++;
        }

        if(quant > sc) {
            ans = min(ans, soma);
        } else break;
    }

    printf("%lld\n", ans);
    return 0;
}