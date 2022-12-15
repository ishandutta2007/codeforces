#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 405;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int firstGraph[SIZE][SIZE];
vector<int> busGraph[SIZE];
vector<int> trainGraph[SIZE];
int d[SIZE];

void bfs(vector<int> graph[]) {
	//printf("%d %d %d\n", as, bs, cs);
	queue<int> q;
	q.push(1);
	d[1] = 0;
	while(!q.empty()) {
		int x = q.front();
		//printf("%d %d %d\n", x, y, z);
		q.pop();
		for(int aresta : graph[x]) {
			if(d[aresta] == -1) {
				d[aresta] = d[x] + 1;
				q.push(aresta);
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		firstGraph[a][b] = 1;
		firstGraph[b][a] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				continue;
			}
			if(firstGraph[i][j] == 1) {
				trainGraph[i].push_back(j);
			} else {
				busGraph[i].push_back(j);
			}
		}
	}
	memset(d, -1, sizeof(d));
	bfs(trainGraph);
	int dist = d[n];
	if(dist == -1) {
		printf("-1\n");
		return 0;
	}
	memset(d, -1, sizeof(d));
	bfs(busGraph);
	if(d[n] == -1) {
		printf("-1\n");
		return 0;
	}
	dist = max(dist, d[n]);
	printf("%d\n", dist);
	return 0;
}