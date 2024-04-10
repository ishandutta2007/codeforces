#include <bits/stdc++.h>

using namespace std;

int t, n, md;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        vector<vector<int>> a1, a2;
        for(int i = 1; i < n; i *= 2) {
            a1.push_back(vector<int>());
            a2.push_back(vector<int>());
            for(int m = 0; m < n; m++) {
                if((i & m) == 0) a1.back().push_back(m + 1);
                else a2.back().push_back(m + 1);
            }
        }

        int ans = 0;

        for(int i = 0; i < a1.size(); i++) {
            printf("%d %d", a1[i].size(), a2[i].size());
            for(int x : a1[i]) printf(" %d", x);
            for(int x : a2[i]) printf(" %d", x);
            puts("");

            fflush(stdout);

            scanf("%d", &md);
            ans = max(ans, md);
        }

        printf("-1 %d\n", ans);
        fflush(stdout);
    }
    return 0;
}