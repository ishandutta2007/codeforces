#include <bits/stdc++.h>
using namespace std;

int n;
bool chk[100010], vis[100010];
vector<pair<int, int> > ans;

int main() {
    for (int i = 2; i <= 100000; i++) if (!chk[i]) {
        for (int j = i + i; j <= 100000; j += i) chk[j] = 1;
    }
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        ans.push_back({i, i + 1});
    }
    ans.push_back({1, n});
    int cur = 1;
    while (chk[ans.size()]) {
        while (vis[cur]) cur++;
        ans.push_back({cur, cur + 2});
        vis[cur] = vis[cur + 2] = 1;
    }
    printf("%d\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}