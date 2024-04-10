#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, maxm = 10000010;
int T, n, K, a[maxn], mn[maxm], f[maxn][21], lst[maxm];
vector<int> cand[maxn];

int main() {
    for (int i = 2; i <= 10000000; i++) if (!mn[i]) {
        mn[i] = i;
        for (long long j = 1LL * i * i; j <= 10000000; j += i) mn[j] = i;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            int t = 1;
            while (a[i] > 1) {
                int x = mn[a[i]], c = 0;
                while (!(a[i] % x)) a[i] /= x, c++;
                if (c & 1) t *= x;
            }
            a[i] = t, lst[a[i]] = 0;
        }
        for (int i = 0; i <= n; i++) {
            memset(f[i], 0x3f, sizeof(f[i]));
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            cand[i] = cand[i - 1];
            cand[i].push_back(lst[a[i]]), lst[a[i]] = i;
            stable_sort(cand[i].begin(), cand[i].end(), greater<int>());
            cand[i].resize(unique(cand[i].begin(), cand[i].end()) - cand[i].begin());
            while (cand[i].size() > K + 1) cand[i].pop_back();
            for (int j = 0; j <= K; j++) {
                for (int k = 0; k <= j && k < cand[i].size(); k++) {
                    f[i][j] = min(f[i][j], f[cand[i][k]][j - k] + 1);
                }
            }
        }
        printf("%d\n", *min_element(f[n], f[n] + K + 1));
    }
    return 0;
}