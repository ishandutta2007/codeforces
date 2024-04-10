#include<bits/stdc++.h>
using namespace std;

typedef double ld;

const int MAXN = 2e3;
int N;
ld P[MAXN][MAXN];

ld dist[MAXN];
ld prob[MAXN];
bool vis[MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int v; scanf("%d", &v);
			P[i][j] = v;
			P[i][j] /= 100;
		}
	}
	for(int i = 0; i < N; i++) {
		prob[i] = 1;
		dist[i] = 1;
	}
	prob[N - 1] = 0;
	dist[N - 1] = 0;

	for(int t = 0; t < N; t++) {
		int cur = -1;
		ld d = 0;
		for(int i = 0; i < N; i++) {
			if(vis[i]) continue;
			// safe, as prob goes down at least to 99/100
			if(prob[i] >= 0.9999) continue;
			ld v = dist[i] / (1 - prob[i]);
			if(cur == -1 || v < d) {
				cur = i;
				d = v;
			}
		}

		if(cur == -1) break;

		dist[cur] = d;
		vis[cur] = true;

		if(cur == 0) break;

		for(int i = 0; i < N; i++) {
			if(vis[i]) continue;
			dist[i] += prob[i] * P[i][cur] * dist[cur];
			prob[i] *= 1 - P[i][cur];
		}
	}

	assert(vis[0]);

	cout << fixed << setprecision(20) << dist[0] << '\n';
	return 0;
}