#include <stdio.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
#define MAXN 100000
#define INF 1500000000

struct edge {
    int dest, cost;
};


int dist[MAXN];
vector<edge> adj[MAXN];
vector<int> forbidden[MAXN];

struct compara {
bool operator()(int a, int b) {
    if (dist[a] != dist[b]) return dist[a]<dist[b];
    else return a<b;
}
};

set<int, compara> heap;

int main() {
    scanf("%d %d", &n, &m);

    dist[0] = 0;
    heap.insert(0);
    for (int i = 1; i < n; i++) {
        dist[i] = INF;
        heap.insert(i);
    }

    for (int i = 0; i < m; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;

        edge n = {b, c};
        adj[a].push_back(n);
        n.dest = a;
        adj[b].push_back(n);
    }

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        for (int j = 0; j < num; j++) {
            int f;
            scanf("%d", &f);
            forbidden[i].push_back(f);
        }
    }

    while (!heap.empty()) {
        int curr = *heap.begin();
        heap.erase(heap.begin());

        if (curr == n-1) {
            if (dist[curr] != INF) printf("%d\n", dist[curr]);
            else printf("-1\n");

            return 0;
        }

        int t = dist[curr];
        for (int i = 0; i < forbidden[curr].size(); i++) {
            if (forbidden[curr][i] > t) break;
            else if (forbidden[curr][i] == t) t++;
        }

        for (int e = 0; e < adj[curr].size(); e++) {
            int v = adj[curr][e].dest;
            int c = adj[curr][e].cost;

            if (heap.find(v) != heap.end()) {
                heap.erase(v);
                dist[v] = min(dist[v], t + c);
                heap.insert(v);
            }
        }
    }
}