// Codeforces Beta Round #77
// Problem E -- Lucky Country
#include <cstdio>
#include <cstring>

const int N = 222222;
const int INF = 1000000000;

int n, m, s[N], f[N], c[N], q[N], dp[2][N];

int find(int i){
	if(f[i] != i){
		f[i] = find(f[i]);
	}
	return f[i];
}

void merge(int i, int j){
	if(find(i) != find(j)){
		s[find(i)] += s[find(j)];
		f[find(j)] = find(i);
	}
}

bool isLucky(int n){
	for(; n; n /= 10){
		if(n % 10 != 4 && n % 10 != 7){
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i){
		s[i] = 1;
		f[i] = i;
	}
	for(int i = 1; i <= m; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		merge(a, b);		
	}
	memset(c, 0, sizeof(c));
	int p = 0;
	dp[p][0] = 0;
	for(int i = 1; i <= n; ++ i){
		if(find(i) == i){
			c[s[i]] += 1;
		}
		dp[p][i] = INF;
	}
	for(int i = 1; i <= n; ++ i)
		if(c[i]){
			p ^= 1;
			for(int r = 0; r < i; ++ r){
				int hd = 0;
				int tl = 0;
				for(int k = 0; k * i + r <= n; ++ k){
					while(hd != tl && dp[p ^ 1][q[hd] * i + r] - q[hd] > dp[p ^ 1][k * i + r] - k){
						tl -= 1;
					}
					q[tl ++] = k;
					while(hd != tl && k - q[hd] > c[i]){
						hd += 1;
					}
					dp[p][k * i + r] = dp[p ^ 1][q[hd] * i + r] + k - q[hd];
				}
			}
			/*
			for(int j = 0; j <= n; ++ j){
				printf("%12d", dp[p][j]);
			}
			printf("\n");
			*/
		}
	int result = INF;
	for(int i = 1; i <= n; ++ i){
		if(isLucky(i) && dp[p][i] < result){
			result = dp[p][i];
		}
	}
	printf("%d\n", result == INF? -1: result - 1);
	return 0;
}