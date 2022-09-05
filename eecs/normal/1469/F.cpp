#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, a[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
vector<pair<int, int>> cand;

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, greater<int>());
    int cur = 1;
    for (Q.emplace(0, 1); cur <= n && !Q.empty(); cur++) {
        auto p = Q.top(); Q.pop();
        int d = p.first;
        cand.emplace_back(a[cur], d);
        if (p.second > 1) Q.emplace(d + 1, p.second - 1);
        int o = (a[cur] + 1) / 2, l = o - 1, r = o + 1;
        Q.emplace(d + 2, l), Q.emplace(d + 2, a[cur] - r + 1);
    }
    auto chk = [&](int x) {
        long long num = 1;
        for (auto p : cand) if (p.second < x - 1) {
            int d = p.second, o = (p.first + 1) / 2;
            int l = o - 1, r = o + 1;
            num += l - max(1, o - (x - d - 1)) + 1;
            num += min(p.first, o + (x - d - 1)) - r;
        }
        return num >= K;
    };
    int l = 0, r = 500000, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}