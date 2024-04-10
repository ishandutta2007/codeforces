#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 200000;

vector<int> g[1 + MAXN];
vector<int> order, v;
bool seen[1 + MAXN];

void DFS(int node) {
    seen[node] = true;
    order.push_back(node);
    for (auto &son : g[node])
        if (!seen[son]) {
            DFS(son);
            order.push_back(node);
        }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int limit = (2 * n) / k;
    if ((2 * n) % k != 0)
        limit++;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1);
    int clone = 1;
    for (auto &it : order) {
        v.push_back(it);
        if (v.size() == limit) {
            printf("%d ", limit);
            for (auto &jt : v)
                printf("%d ", jt);
            printf("\n");
            v.clear();
            clone++;
        }
    }
    if (v.size()) {
        printf("%d ", v.size());
        for (auto &jt : v)
            printf("%d ", jt);
        printf("\n");
        clone++;
    }
    while (clone <= k) {
        printf("1 1\n");
        clone++;
    }
    return 0;
}