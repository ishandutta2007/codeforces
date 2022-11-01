#include <bits/stdc++.h>

using namespace std;

int n, q, a[100010], l[5050], r[5050], maxi[5050], tmax;
double p[5050];

vector<int> add[100010], adj[100010];

double prob[5050][10050];

void solve(int id) {
    for(int i = 0; i <= 2*q; i++) {
        prob[id][i] = (maxi[id] <= tmax - q + i);
    }
    for(int v : adj[id]) {
        solve(v);
        for(int i = 0; i <= 2*q; i++)
            prob[id][i] *= prob[v][i];
    }
    for(int i = 2*q; i >= 0; i--) {
        prob[id][i] = p[id] * (i ? prob[id][i-1] : 0) + (1 - p[id]) * prob[id][i];
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        tmax = max(tmax, a[i]);
    }

    fill(maxi, maxi + 5050, -123456);
    l[0] = 0, r[0] = n, p[0] = 0;
    add[0].push_back(0);
    for(int i = 1; i <= q; i++) {
        scanf("%d %d %lf", &l[i], &r[i], &p[i]);
        add[l[i]].push_back(i);
    }

    set<pair<pair<int, int>, int>> segm;
    segm.insert({{n, 0}, 0});
    for(int i = 1; i <= n; i++) {
        while(segm.begin()->first.first < i) segm.erase(segm.begin());
        sort(add[i].begin(), add[i].end(), [&](int a, int b) {
             return tie(r[a], a) > tie(r[b], b);
        });
        for(int id : add[i]) {
            int pai = segm.begin()->second;
            adj[pai].push_back(id);
            segm.insert({{r[id], -l[id]}, id});
        }
        maxi[segm.begin()->second] = max(maxi[segm.begin()->second], a[i]);
    }

    solve(0);

    double ans = 0;
    for(int i = 1; i <= 2*q; i++) {
        ans += (prob[0][i] - prob[0][i-1]) * (tmax - q + i);
    }

    printf("%.9f\n", ans);
    return 0;
}