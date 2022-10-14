#include <bits/stdc++.h>

const int N = 1000000;

bool resolved[N];
std::vector<int> graph[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; ++ i) {
        scanf("%d%d", &a, &b);
        graph[a - 1].push_back(b - 1);
    }
    std::vector<int> candidates, result;
    for (int i = 0; i < n; ++ i) {
        if (!resolved[i]) {
            candidates.push_back(i);
            for (int j : graph[i]) {
                resolved[j] = true;
            }
        }
    }
    memset(resolved, 0, sizeof(resolved));
    std::reverse(candidates.begin(), candidates.end());
    for (int i : candidates) {
        if (!resolved[i]) {
            result.push_back(i);
            for (int j : graph[i]) {
                resolved[j] = true;
            }
        }
    }
    printf("%d\n", static_cast<int>(result.size()));
    for (int i : result) {
        printf("%d\n", i + 1);
    }
}