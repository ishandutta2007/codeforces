#include<iostream>
#include<cstring>

using namespace std;

const int INF = 1 << 30;
const int MAXN = 2000;
const int MAXM = 2000;

const char DIMA[] = {'D', 'I', 'M', 'A'};

const int mx[] = {-1, 0, 1, 0}, my[] = {0, -1, 0, 1};

int N, M;
char C[MAXN][MAXM];

int dist[MAXN][MAXM]; // dist 0 means not visited, dist -1 means in stack

int dfs(int i, int j) {
	if(dist[i][j] > 0) return dist[i][j];
	else if(dist[i][j] == -1) return INF;
	else {
		dist[i][j] = -1;

		int d = 0;
		int p = 0;
		while(DIMA[p] != C[i][j]) p++;
		p++, p %= 4;
		for(int m = 0; m < 4; m++) {
			int x = i + mx[m];
			int y = j + my[m];
			if(DIMA[p] == C[x][y]) {
				int v = dfs(x, y);
				if(v == INF) return dist[i][j] = INF;
				else if(v > d) d = v;
			}
		}
		
		return dist[i][j] = d + 1;
	}
}

int go() {
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(DIMA[0] == C[i][j]) {
				int v = dfs(i, j);
				if(v == INF) return INF;
				else if(v > ans) ans = v;
			}
		}
	}
	return ans / 4;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> C[i];
	int v = go();
	if(v == INF) cout << "Poor Inna!" << '\n';
	else if(v == 0) cout << "Poor Dima!" << '\n';
	else cout << v << '\n';
	return 0;
}