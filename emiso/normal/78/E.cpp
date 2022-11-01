#include <bits/stdc++.h>
#define MN 110

using namespace std;
typedef pair<int,int> pii;

const int MAXN = 1010;
const int INF = 1000000000;

struct edge {
	int a, b, cap, flow;
};

int n, s = MAXN-2, t = MAXN-1, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int T, cocoX, cocoY;
int scientists[MN][MN], reator[MN][MN], capsules[MN][MN];
int visit[MN][MN], dist[MN][MN][2];

int dX[] = {-1, 0, 1, 0};
int dY[] = {0, 1, 0, -1};

bool check(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void bfs1(int x, int y, int k) {
    memset(visit, 0, sizeof visit);

    visit[x][y] = 1;
    dist[x][y][k] = 0;

    queue<pii> fila;
    fila.push({x,y});

    while(!fila.empty()) {
        pii u = fila.front();
        int old_dist = dist[u.first][u.second][k];
        fila.pop();
        if(old_dist == T) continue;

        for(int i=0; i<4; i++) {
            int nx = u.first  + dX[i];
            int ny = u.second + dY[i];
            if(check(nx, ny) && (k || old_dist + 1 <= dist[nx][ny][1])) {
                if(!visit[nx][ny] && reator[nx][ny] == 0) {
                    if (k || old_dist + 1 < dist[nx][ny][1]) {
                        dist[nx][ny][k] = old_dist + 1;
                        fila.push({nx, ny});
                    }
                    visit[nx][ny] = 1;
                }
            }
        }
    }

    if(k) return;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visit[i][j] && capsules[i][j] > 0) {
                add_edge(x*n + y, 500 + i*n + j, 10);
            }
        }
    }
}

int main() {
    char inputa[MN];
    scanf("%d %d", &n, &T);

    for(int i=0;i<n;i++) {
        scanf("%s", inputa);

        for(int j=0;j<n;j++) {
            if(isdigit(inputa[j])) {
                scientists[i][j] = inputa[j] - '0';
            }
            else if(inputa[j] == 'Z') {
                cocoX = i;
                cocoY = j;
            }
            else {
                reator[i][j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++) {
        scanf("%s", inputa);

        for(int j=0;j<n;j++)
            if(isdigit(inputa[j]))
                capsules[i][j] = inputa[j] - '0';
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j][1] = INF;

    bfs1(cocoX, cocoY, 1);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            if(scientists[i][j] > 0) {
                add_edge(s, i*n + j, scientists[i][j]);
                bfs1(i, j, 0);
            }
            if(capsules[i][j] > 0)
                add_edge(500 + i*n + j, t, capsules[i][j]);
        }

    printf("%d\n", dinic());

    return 0;
}