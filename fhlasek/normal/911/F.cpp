/* Written by Filip Hlasek 2017 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, b) for (int i = 0; i < (b); i++)

using namespace std;

#define MAXN 222222
vector<int> graph[MAXN];
int N;

int dist[MAXN], dist1[MAXN], parent[MAXN];

vector<int> vertices;

void dfs(int v, int f = -1) {
    REP(i, graph[v].size()) if (graph[v][i] != f) {
        dist[graph[v][i]] = dist[v] + 1;
        parent[graph[v][i]] = v;
        dfs(graph[v][i], v);
    }
    vertices.push_back(v);
}

int path[MAXN], P = 0, on_path[MAXN];

int find_furthest() {
    int a = 0;
    REP(i, N) if (dist[i] > dist[a]) a = i;
    return a;
}

vector<pair<pair<int, int>, int> > res;

int main(int argc, char* argv[]) {
    scanf("%d", &N);
    REP(i, N - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0);
    int f = find_furthest();

    dist[f] = 0;
    vertices.clear();
    dfs(f);
    REP(i, N) dist1[i] = dist[i];
    int g = find_furthest();

    dist[g] = 0;
    vertices.clear();
    dfs(g);

    int p = f;
    path[P++] = p;
    on_path[p] = true;
    while (p != g) {
        p = parent[p];
        path[P++] = p;
        on_path[p] = true;
    }

    long long ans = 0;
    REP(ii, N) {
        int i = vertices[ii];
        if (!on_path[i]) {
            if (dist1[i] > dist[i]) {
                ans += dist1[i];
                res.push_back(make_pair(make_pair(i, f), i));
            } else {
                ans += dist[i];
                res.push_back(make_pair(make_pair(i, g), i));
            }
        }
    }

    REP(i, P - 1) {
        ans += P - 1 - i;
        res.push_back(make_pair(make_pair(path[i], path[P - 1]), path[i]));
    }

    cout << ans << endl;
    REP(i, res.size()) {
        printf("%d %d %d\n",
               res[i].first.first + 1,
               res[i].first.second + 1,
               res[i].second + 1);
    }

    return 0;
}