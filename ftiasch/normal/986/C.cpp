#include <bits/stdc++.h>

const int N = 22;

int n, m;
std::bitset<1 << N + 1> a, visited;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, x; i < m; ++ i) {
        scanf("%d", &x);
        a.set(x);
    }
    int result = 0;
    int full = (1 << n + 1) - 1;
    for (int s = 0; s < 1 << n; ++ s) {
        if (a.test(s) && !visited.test(s << 1)) {
            result ++;
            std::queue<int> queue;
            queue.emplace(s << 1);
            visited.set(s << 1);
            while (!queue.empty()) {
                int u = queue.front();
                queue.pop();
                if (u & 1) {
                    if (a.test(u >> 1) && !visited.test(u ^ 1)) {
                        visited.set(u ^ 1);
                        queue.emplace(u ^ 1);
                    }
                    for (int i = 1; i <= n; ++ i) {
                        int uu = u ^ (1 << i);
                        if ((u >> i & 1) && !visited.test(uu)) {
                            visited.set(uu);
                            queue.emplace(uu);
                        }
                    }
                } else {
                    int comp = u ^ full;
                    if (!visited.test(comp)) {
                        visited.set(comp);
                        queue.emplace(comp);
                    }
                }
            }
        }
    }
    printf("%d\n", result);
}