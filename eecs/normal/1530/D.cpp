#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], cnt[maxn], ans[maxn], mark[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(cnt + 1, cnt + n + 1, 0);
        fill(ans + 1, ans + n + 1, 0);
        int k = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (!cnt[a[i]]) {
                k++, ans[i] = a[i], cnt[a[i]]++;
            }
        }
        fill(mark + 1, mark + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (ans[i]) mark[ans[i]] = 1;
        }
        set<int> S, T;
        for (int i = 1; i <= n; i++) if (!mark[i]) {
            if (!ans[i]) S.insert(i);
            else T.insert(i);
        }
        bool flag = 0;
        int tmp;
        for (int i = 1; i <= n; i++) if (!ans[i]) {
            if (!S.empty() && (S.size() > 1 || i != *S.begin())) {
                if (i == *S.begin()) ans[i] = *S.rbegin(), S.erase(*S.rbegin());
                else ans[i] = *S.begin(), S.erase(*S.begin());
            } else {
                if (T.empty()) ans[i] = i;
                else if (i == *T.begin()) ans[i] = *T.rbegin(), T.erase(*T.rbegin());
                else ans[i] = *T.begin(), T.erase(*T.begin());
            }
            if (i == ans[i]) flag = 1, ans[i] = 0, tmp = a[i];
        }
        if (flag) {
            assert(k == n - 1);
            int pos;
            for (int i = 1; i <= n; i++) {
                if (a[i] == tmp && ans[i]) pos = i;
            }
            fill(ans + 1, ans + n + 1, 0);
            for (int i = 1; i <= n; i++) if (i ^ pos) {
                ans[i] = a[i];
            }
            S.clear(), T.clear(), fill(mark + 1, mark + n + 1, 0);
            for (int i = 1; i <= n; i++) {
                if (ans[i]) mark[ans[i]] = 1;
            }
            for (int i = 1; i <= n; i++) if (!mark[i]) {
                if (!ans[i]) S.insert(i);
                else T.insert(i);
            }
            for (int i = 1; i <= n; i++) if (!ans[i]) {
                if (!S.empty() && (S.size() > 1 || i != *S.begin())) {
                    if (i == *S.begin()) ans[i] = *S.rbegin(), S.erase(*S.rbegin());
                    else ans[i] = *S.begin(), S.erase(*S.begin());
                } else {
                    if (i == *T.begin()) ans[i] = *T.rbegin(), T.erase(*T.rbegin());
                    else ans[i] = *T.begin(), T.erase(*T.begin());
                }
            }
        }
        printf("%d\n", k);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}