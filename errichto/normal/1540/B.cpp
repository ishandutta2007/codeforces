#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int half = (mod + 1) / 2;

const int nax = 205;
vector<int> edges[nax];
int dist[nax][nax];
int p_win[nax][nax];

void dfs(int a, int parent, int start) {
	for(int b : edges[a]) {
		if(b != parent) {
			dist[start][b] = dist[start][a] + 1;
			dfs(b, a, start);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	// 1) compute distances
	for(int a = 1; a <= n; ++a) {
		dfs(a, -1, a);
	}
	// 2) dp
	// p_win[3][5] is prob. of getting disease first to node with distance 3 from the start
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			if(i == 0) {
				p_win[i][j] = 1;
			}
			else if(j == 0) {
				p_win[i][j] = 0;
			}
			else {
				// p_win[i][j] = 0.5 * p_win[i-1][j] + 0.5 * p_win[i][j-1];
				p_win[i][j] = (long long) half * (p_win[i-1][j] + p_win[i][j-1]) % mod;
			}
		}
	}
	// 3) solution
	int answer = 0;
	for(int a = 1; a <= n; ++a) {
		for(int b = 1; b < a; ++b) {
			// probability that a goes before b
			int d = dist[a][b];
			assert(d != 0);
			for(int v = 1; v <= n; ++v) {
				int x = (dist[a][v] - dist[b][v] + d) / 2;
				assert(0 <= x && x <= d);
				answer += p_win[x][d-x];
				if(answer >= mod) {
					answer -= mod;
				}
			}
		}
	}
	
	// you can compute 1/n without modular inverse in O(N)
	
	// A / n = x
	// k * mod + A = n * x
	for(int k = 0; k <= n; ++k) {
		long long tmp = (long long) k * mod + answer;
		if(tmp % n == 0) {
			printf("%lld\n", tmp / n);
			return 0;
		}
	}
	assert(false);
	// printf("%lld\n", (long long) answer * x % mod);
}