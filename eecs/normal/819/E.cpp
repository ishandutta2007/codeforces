#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> ans;

#define twice(p) p, p;
int main() {
    scanf("%d", &n);
    if (n & 1) {
        ans = {{1, 2, 3}, {1, 2, 3}};
        for (int i = 5; i <= n; i += 2) {
            int s = i - 1, t = i;
            twice(ans.push_back({s, 1, t}));
            for (int j = 2; j + 1 < i; j += 2) {
                twice(ans.push_back({s, j, t, j + 1}));
            }
        }
    } else {
        ans = {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}};
        for (int i = 6; i <= n; i += 2) {
            int s = i - 1, t = i;
            ans.push_back({s, 1, t});
            ans.push_back({s, 2, t});
            ans.push_back({s, 1, t, 2});
            for (int j = 3; j + 1 < i; j += 2) {
                twice(ans.push_back({s, j, t, j + 1}));
            }
        }
    }
    printf("%d\n", ans.size());
    for (auto &v : ans) {
        printf("%d", v.size());
        for (int x : v) printf(" %d", x);
        putchar('\n');
    }
    return 0;
}