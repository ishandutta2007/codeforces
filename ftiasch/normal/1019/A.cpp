#include <bits/stdc++.h>

const int N = 3000;

std::vector<int> cost[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int _ = 0, p, c; _ < n; ++ _) {
        scanf("%d%d", &p, &c);
        cost[p - 1].push_back(c);
    }
    for (int i = 0; i < m; ++ i) {
        std::sort(cost[i].begin(), cost[i].end());
    }
    long long result = 1e18;
    for (int need = 1; need <= n; ++ need) {
        std::vector<int> rest;
        int count = cost[0].size();
        long long total = 0;
        for (int i = 1; i < m; ++ i) {
            int extra = std::max(static_cast<int>(cost[i].size()) - (need - 1), 0);
            for (int j = 0; j < extra; ++ j) {
                count ++;
                total += cost[i][j];
            }
            for (int j = extra; j < static_cast<int>(cost[i].size()); ++ j) {
                rest.push_back(cost[i][j]);
            }
        }
        std::sort(rest.begin(), rest.end());
        for (int j = 0; j < need - count; ++ j) {
            total += rest[j];
        }
        result = std::min(result, total);
    }
    std::cout << result << std::endl;
}