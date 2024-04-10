#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];
set<int> S[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), S[a[i]].insert(i);
        }
        int p = 1;
        vector<int> ans;
        while (p <= n) {
            if (S[0].empty()) {
                ans.push_back(0);
                S[a[p]].erase(p), p++; continue;
            }
            int lst = 0;
            for (int i = 0; ; i++) {
                if (S[i].empty()) {
                    ans.push_back(i);
                    for (int j = p; j <= lst; j++) S[a[j]].erase(j);
                    p = lst + 1; break;
                }
                lst = max(lst, *S[i].begin());
            }
        }
        printf("%d\n", ans.size());
        for (int x : ans) printf("%d ", x);
        putchar('\n');
    }
    return 0;
}