#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

const int N = 1000000;

int n, m, source, target;
std::vector <int> graph[N], reversed_graph[N];

int minimum[N], active_count[N];
std::vector <int> buckets[N + 1];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        int u, v;
        scanf("%d%d", &u, &v);
        u --, v --;
        graph[u].push_back(v);
        reversed_graph[v].push_back(u);
    }
    scanf("%d%d", &source, &target);
    source --, target --;
    for (int i = 0; i < n; ++ i) {
        minimum[i] = n;
        active_count[i] = graph[i].size();
    }
    minimum[target] = 0;
    buckets[0].push_back(target);
    for (int distance = 0; distance < n; ++ distance) {
        std::vector <int> &bucket = buckets[distance];
        while (!bucket.empty()) {
            int u = bucket.back();
            bucket.pop_back();
            if (active_count[u] < 0) {
                continue;
            }
            active_count[u] = -1;
            foreach(it, reversed_graph[u]) {
                int v = *it;
                minimum[v] = std::min(minimum[v], minimum[u] + 1);
                active_count[v] --;
                if (active_count[v] == 0) {
                    minimum[v] = std::min(minimum[v], minimum[u]);
                }
                buckets[minimum[v]].push_back(v);
            }
        }
    }
    printf("%d\n", minimum[source] < n ? minimum[source] : -1);
    return 0;
}