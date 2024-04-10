#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

vector<int> g[1 + MAXN];
int color[1 + MAXN];

void DFS(int node, int father) {
    int number = 1;
    for (auto &son : g[node])
        if (son != father) {
            while (number == color[node] || number == color[father])
                number++;
            color[son] = number;
            number++;
            DFS(son, node);
        }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int answer = 1, root = 0;
    for (int i = 1; i <= n; i++)
        if (g[i].size() + 1 > answer) {
            answer = g[i].size() + 1;
            root = i;
        }
    printf("%d\n", answer);
    color[root] = 1;
    DFS(root, 0);
    for (int i = 1; i <= n; i++)
        printf("%d ", color[i]);
    return 0;
}