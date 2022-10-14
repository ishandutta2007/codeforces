#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

const int N = 100000;
const int INF = 1000000000;

int n, m, d, parent[N], maxDepth[N];
bool marked[N];
std::vector <int> edges[N];

std::vector <int> find(int source) {
    std::vector <int> distance(n, -1);
    distance[source] = 0;
    std::queue <int> queue;
    queue.push(source);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        foreach (iter, edges[u]) {
            int v = *iter;
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                queue.push(v);
            }
        }
    }
    return distance;
}

int main() {
    scanf("%d%d%d", &n, &m, &d);
    memset(marked, 0, sizeof(marked));
    for (int i = 0; i < m; ++ i) {
        int v;
        scanf("%d", &v);
        v --;
        marked[v] = true;
    }
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --, b --;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int v = 0;
    while (!marked[v]) {
        v ++;
    }
    std::vector <int> distance1 = find(v);
    int u = v;
    for (int i = 0; i < n; ++ i) {
        if (marked[i] && distance1[i] > distance1[u]) {
            u = i;
        }
    }
    std::vector <int> distance2 = find(u);
    v = u;
    for (int i = 0; i < n; ++ i) {
        if (marked[i] && distance2[i] > distance2[v]) {
            v = i;
        }
    }
    distance1 = find(v);
    int answer = 0;
    for (int i = 0; i < n; ++ i) {
        answer += std::max(distance1[i], distance2[i]) <= d;
    }
    printf("%d\n", answer);
    //memset(parent, -1, sizeof(parent));
    //std::vector <int> queue;
    //queue.push_back(0);
    //while (!queue.empty()) {
    //    int u = queue.front();
    //    foreach (iter, edges[u]) {
    //        int v = *iter;
    //        if (v != parent[u]) {
    //            parent[v] = u;
    //            queue.push(v);
    //        }
    //    }
    //}
    //for (int i = n - 1; i >= 0; -- i) {
    //    int u = queue[i];
    //    maxDepth[u] = -INF;
    //}
    return 0;
}