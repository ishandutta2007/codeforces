#include <cstdio>
//#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100000;

vector<int> g[1 + 2 * MAXN];
int boy[1 + MAXN], girl[1 + MAXN];
int color[1 + 2 * MAXN];

bool Try(int n) {
    queue<int> Queue;
    for (int i = 1; i <= n; i++)
        if (!color[i]) {
            color[i] = 1;
            Queue.push(i);
            while (!Queue.empty()) {
                int node = Queue.front();
                Queue.pop();
                for (auto &neighbour : g[node]) {
                    if (color[neighbour] == color[node])
                        return false;
                    if (!color[neighbour]) {
                        color[neighbour] = 3 - color[node];
                        Queue.push(neighbour);
                    }
                }
            }
        }
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &boy[i], &girl[i]);
        g[boy[i]].push_back(girl[i]);
        g[girl[i]].push_back(boy[i]);
    }
    for (int i = 2; i < 2 * n; i += 2) {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    g[2 * n].push_back(1);
    g[1].push_back(2 * n);
    if (!Try(2 * n)) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", color[boy[i]], color[girl[i]]);
    return 0;
}