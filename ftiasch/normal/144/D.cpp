// Codeforces Round #103
// Problem D -- Missile Silos
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 111111;
const int M = 222222;
const int INF = 1000000000;

int n, m, s, l,
    edgeCount, firstEdge[N], to[M], length[M], nextEdge[M],
    dist[N];
priority_queue <pair <int, int> > heap;

void addEdge(int u, int v, int w) {
    to[edgeCount] = v;
    length[edgeCount] = w;
    nextEdge[edgeCount] = firstEdge[u];
    firstEdge[u] = edgeCount ++;
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    s --;
    edgeCount = 0;
    memset(firstEdge, -1, sizeof(firstEdge));
    for (int i = 0; i < m; ++ i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a --, b --;
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    scanf("%d", &l);
    for (int i = 0; i < n; ++ i) {
        dist[i] = INF;
    }
    dist[s] = 0;
    heap.push(make_pair(0, s));
    while (!heap.empty()) {
        pair <int, int> ret = heap.top();
        heap.pop();
        int u = ret.second;
        if (-ret.first == dist[ret.second]) {
            for (int iter = firstEdge[u]; 
                    iter != -1; iter = nextEdge[iter]) {
                int v = to[iter];
                if (dist[u] + length[iter] < dist[v]) {
                    dist[v] = dist[u] + length[iter];
                    heap.push(make_pair(-dist[v], v));
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++ i) {
        if (dist[i] == l) {
            result ++;
        }
    }
    for (int i = 0; i < edgeCount; ++ i) {
        int a = to[i];
        int b = to[i ^ 1];
        int c = length[i];
        if (dist[a] < l && 2 * l < dist[b] + c + dist[a]) {
            result ++;
        }
        if ((i & 1) && abs(dist[a] - dist[b]) != c 
                && 2 * l == dist[b] + c + dist[a]) {
            result ++;
        }
    }
    printf("%d\n", result);
    return 0;
}