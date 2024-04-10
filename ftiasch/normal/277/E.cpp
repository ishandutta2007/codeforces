#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

const int N = 400;
const double INF = 1e10;
const double EPS = 1e-9;

int n;
int x[N], y[N];

const int V = (N << 1) + 2;

int capacity[V][V];
double cost[V][V];

void add_edge(int u, int v, double w, int c) {
    cost[u][v] = w;
    capacity[u][v] = c;
    cost[v][u] = -w;
}

double sqr(double x) {
    return x * x;
}

bool visit[V];
int back[V];
double distance[V];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", x + i, y + i);
    }
    int root_id = std::max_element(y, y + n) - y;
    memset(capacity, 0, sizeof(capacity));
    int source = n << 1;
    int target = source + 1;
    for (int i = 0; i < n; ++ i) {
        add_edge(source, i, 0, 2);
        add_edge(n + i, target, 0, i == root_id ? 0 : 1);
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (y[i] > y[j]) {
                add_edge(i, n + j, sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])), 1);
            }
        }
    }
    double answer = 0;
    while (true) {
        for (int i = 0; i <= target; ++ i) {
            visit[i] = false;
            distance[i] = INF;
        }
        visit[source] = true;
        std::queue <int> queue;
        queue.push(source);
        distance[source] = 0;
        memset(back, -1, sizeof(back));
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            visit[u] = false;
            for (int v = 0; v <= target; ++ v) {
                if (capacity[u][v] > 0 && distance[u] + cost[u][v] + EPS < distance[v]) {
                    back[v] = u;
                    distance[v] = distance[u] + cost[u][v];
                    if (!visit[v]) {
                        visit[v] = true;
                        queue.push(v);
                    }
                }
            }
        }
        if (back[target] == -1) {
            break;
        }
        for (int i = target; i != source; i = back[i]) {
            answer += cost[back[i]][i];
            capacity[back[i]][i] --;
            capacity[i][back[i]] ++;
        }
    }
    for (int i = 0; i < n; ++ i) {
        if (capacity[n + i][target] > 0) {
            puts("-1");
            return 0;
        }
    }
    printf("%.8f\n", answer);
    return 0;
}