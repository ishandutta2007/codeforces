// Codeforces Beta Round #71
// Problem D -- Password
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 22222;
const int K = 22;
const int INF = 100000000;

int n, k, l, a[N], m, point[K], cost[K][K], dist[N], queue[N], dp[1 << K];
bool light[N];

int dfs(int mask){
	if(dp[mask] == -1){
		dp[mask] = INF;
		for(int i = 0; i < m; ++ i){
			if(mask & (1 << i)){
				for(int j = 0; j < m; ++ j){
					if(i != j && (mask & (1 << j))){
						dp[mask] = min(dp[mask], dfs(mask ^ (1 << i) ^ (1 << j)) + cost[i][j]);
					}
				}
			}
		}
	}
	return dp[mask];
}

int main(){
	scanf("%d%d%d", &n, &k, &l);
	memset(light, 0, sizeof(light));
	for(int i = 0; i < k; ++ i){
		int x;
		scanf("%d", &x);
		light[x] ^= 1;
	}
	for(int i = 0; i < l; ++ i){
		scanf("%d", a + i);
	}
	for(int i = 0; i < l; ++ i){
		a[i + l] = -a[i];
	}
	l += l;
	m = 0;
	for(int i = 0; i <= n; ++ i){
		if(light[i] != light[i + 1]){
			point[m ++] = i;
		}
	}
	for(int i = 0; i < m; ++ i){
		for(int j = 0; j <= n; ++ j){
			dist[j] = INF;
		}
		dist[point[i]] = 0;
		int head = 0;
		int tail = 0;
		queue[tail ++] = point[i];
		while(head != tail){
			int j = queue[head ++];
			for(int iter = 0; iter < l; ++ iter){
				if(0 <= j + a[iter] && j + a[iter] <= n && dist[j + a[iter]] == INF){
					dist[j + a[iter]] = dist[j] + 1;
					queue[tail ++] = j + a[iter];
				}
			}
		}
		for(int j = 0; j < m; ++ j){
			cost[i][j] = dist[point[j]];
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int answer = dfs((1 << m) - 1);
	printf("%d\n", answer == INF? -1: answer);
	return 0;
}