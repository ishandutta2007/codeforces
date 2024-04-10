#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, x[maxn];
vector<pair<int, int>> cand[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2) {
        scanf("%d", &x[i]);
        for (int j = 1; j * j <= x[i]; j++) if (!(x[i] % j)) {
            int s1 = j, s2 = x[i] / j;
            if ((s1 & 1) ^ (s2 & 1)) continue;
            cand[i].emplace_back((s1 + s2) / 2, (s2 - s1) / 2);
        }
        sort(cand[i].begin(), cand[i].end());
        if (cand[i].empty()) puts("No"), exit(0);
    }
    int lst = 0;
    vector<long long> ans;
    for (int i = 2; i <= n; i += 2) {
        bool flag = 0;
        for (auto p : cand[i]) if (p.second > lst) {
            ans.push_back(1LL * p.second * p.second - 1LL * lst * lst);
            ans.push_back(x[i]);
            flag = 1, lst = p.first; break;
        }
        if (!flag) puts("No"), exit(0);
    }
    puts("Yes");
    for (auto x : ans) printf("%lld ", x);
    return 0;
}