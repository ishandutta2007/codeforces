#include <bits/stdc++.h>

using namespace std;

int n, a[3030], ans[3030], a1 = -1, a2, a3;
pair<int, pair<int, int>> best;
vector<pair<int, int>> v;

pair<int, int> rmq[3030][13];
void build() {
    for(int i = 0; i < n; i++)
        rmq[i][0] = {v[i].first - v[i+1].first, i};

    for(int j = 1;(1 << j) <= n; j++)
        for(int i = 0; i + (1 << j) <= n; i++)
            rmq[i][j] = max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
}

pair<int, int> query(int a, int b) {
    if(a > b) swap(a,b);
    int lg = __builtin_clz(1) - __builtin_clz(b - a + 1);
    return max(rmq[a][lg], rmq[b-(1<<lg)+1][lg]);
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        v.emplace_back(a[i], i);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    v.emplace_back(0, 0);
    build();

    for(int x1 = 1; x1 < n; x1++) {
        for(int x2 = 1; x2 < n; x2++) {
            if(x2 > 2 * x1 || x1 > 2 * x2) continue;

            int L = (max(x1, x2) + 1) / 2, R = min(2*min(x1, x2), n - x1 - x2);
            if(R < L) continue;

            int x3 = query(x1+x2-1+L, x1+x2-1+R).second-x1-x2+1;
            pair<int, pair<int, int>> tmp = {v[x1-1].first - v[x1].first, {v[x1+x2-1].first - v[x1+x2].first, query(x1+x2-1+L, x1+x2-1+R).first}};

            if(a1 == -1 || tmp > best) {
                best = tmp;
                a1 = x1, a2 = x2, a3 = x3;
            }
        }
    }

    for(int i = 0; i < a1; i++) ans[v[i].second] = 1;
    for(int i = a1; i < a1+a2; i++) ans[v[i].second] = 2;
    for(int i = a1+a2; i < a1+a2+a3; i++) ans[v[i].second] = 3;
    for(int i = a1+a2+a3; i < n; i++) ans[v[i].second] = -1;

    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
}