// Codefroces Beta Round #58
// Problem E -- World Evil
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::min;
using std::cout;
using std::endl;

const int N = 5;
const int M = 100000;
const long long INF = 1000000000000000000LL;

int n, m, up[M][N], left[M][N];
long long dp[2][1 << N];

void update(long long &x, long long a){
	x = min(x, a);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i < m; ++ i){
		for(int j = 0; j < n; ++ j){
			scanf("%d", &up[i][j]);
		}
	}	
	for(int i = 0; i < m; ++ i){
		for(int j = 1; j < n; ++ j){
			scanf("%d", &left[i][j]);
		}
		scanf("%d", &left[i][0]);
	}
	int cur = 0;
	for(int j = 0; j < (1 << n); ++ j){
		dp[cur][j] = INF;
	}
	dp[cur][0] = 0;
	for(int i = 1; i < m; ++ i){
		for(int j = 0; j < n; ++ j){
			cur ^= 1;
			for(int mask = 0; mask < (1 << n); ++ mask){
				dp[cur][mask] = INF;
			}
			for(int mask = 0; mask < (1 << n); ++ mask){
				for(int k = 0; k < 2; ++ k){
					long long tmp = 0;
					if(k ^ ((mask & (1 << j)) > 0)){
						tmp += up[i][j];
					}
					if(j && (k ^ ((mask & (1 << (j - 1))) > 0))){
						tmp += left[i][j];
					}
					if(j == n - 1 && (((k ^ ((mask & 1))) > 0))){
						tmp += left[i][0];
					}
					update(dp[cur][(mask & (~(1 << j))) | (k << j)], dp[cur ^ 1][mask] + tmp);
				}
			}
		}
	}
	cout << dp[cur][(1 << n) - 1] << endl;
	return 0;
}