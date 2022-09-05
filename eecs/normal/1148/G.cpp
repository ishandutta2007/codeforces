#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, maxa = maxn * 100;
int n, K, a[maxn];
int tot, pr[maxa], mn[maxa], mu[maxa], cnt[maxa];
vector<int> S, T, d[maxn], bel[maxn];

int main() {
    scanf("%d %d", &n, &K);
    fill(pr, pr + maxa, 1), mu[1] = 1;
    for (int i = 2; i < maxa; i++) {
        if (pr[i]) pr[++tot] = mn[i] = i, mu[i] = -1;
        for (int j = 1; j <= tot && i * pr[j] < maxa; j++) {
            pr[i * pr[j]] = 0, mn[i * pr[j]] = pr[j];
            if (i % pr[j]) mu[i * pr[j]] = -mu[i];
            else { mu[i * pr[j]] = 0; break; }
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        vector<int> V;
        while (a[i] > 1) {
            int x = mn[a[i]];
            while (!(a[i] % x)) a[i] /= x;
            V.push_back(x);
        }
        for (int j = 0; j < 1 << V.size(); j++) {
            int x = 1;
            for (int k = 0; k < V.size(); k++) {
                if (j >> k & 1) x *= V[k];
            }
            d[i].push_back(x);
        }
    }
    auto ins = [&](int i, int coef) {
        for (int x : d[i]) cnt[x] += coef;
    };
    auto test = [&](int i) {
        int s = 0;
        for (int x : d[i]) s += mu[x] * cnt[x];
        return s;
    };
    for (int i = 1; i <= n; i++) {
        if (!test(i)) S.push_back(i), ins(i, 1);
        else T.push_back(i);
    }
    if (S.size() >= K) {
        for (int i = 0; i < K; i++) printf("%d ", S[i]);
        exit(0);
    }
    memset(cnt, 0, sizeof(cnt));
    function<void(int, int, vector<int>&)> solve = [&](int l, int r, vector<int>& V) {
        if (l == r) {
            for (int x : V) bel[S[l]].push_back(x);
            return;
        }
        int mid = (l + r) / 2;
        vector<int> L, R;
        for (int i = l; i <= mid; i++) ins(S[i], 1);
        for (int x : V) (test(x) ? L : R).push_back(x);
        for (int i = l; i <= mid; i++) ins(S[i], -1);
        solve(l, mid, L), solve(mid + 1, r, R);
    };
    solve(0, S.size() - 1, T);
    int sz = 0;
    for (int i = 0; i < S.size(); i++) if (!bel[S[i]].empty()) {
        if ((sz += bel[S[i]].size() + 1) < K) continue;
        for (int j = 0; j <= i; j++) if (!bel[S[j]].empty()) {
            printf("%d %d ", S[j], bel[S[j]].back());
            K -= 2, bel[S[j]].pop_back();
        }
        for (int x : S) {
            while (K && !bel[x].empty()) {
                printf("%d ", bel[x].back());
                K--, bel[x].pop_back();
            }
        }
        break;
    }
    return 0;
}