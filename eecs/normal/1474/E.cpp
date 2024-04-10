#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int pos = (n - 1) / 2;
        vector<int> V = {pos + 1};
        for (int i = 1; i <= pos; i++) V.push_back(i - 1);
        for (int i = pos + 1; i < n - 1; i++) V.push_back(i + 1);
        V.push_back(pos);
        assert(V.size() == n);
        vector<pair<int, int>> ans;
        for (int i = pos; i; i--) ans.emplace_back(i, n - 1);
        for (int i = pos + 1; i < n - 1; i++) ans.emplace_back(i, 0);
        ans.emplace_back(0, n - 1);
        long long w = 0;
        for (auto p : ans) w += 1LL * (p.first - p.second) * (p.first - p.second);
        printf("%lld\n", w);
        for (int x : V) printf("%d ", x + 1);
        printf("\n%d\n", n - 1);
        for (auto p : ans) printf("%d %d\n", p.first + 1, p.second + 1);
    }
    return 0;
}