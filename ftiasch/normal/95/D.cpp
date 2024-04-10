// Codeforces Beta Round #77
// Problem D -- Horse Races
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;
using std::max;

const int N = 1000;
const int MOD = 1000000007;

struct Integer{
	int size, digit[N + 1];
	
	void initialize(){
		char buffer[N + 2];
		scanf("%s", buffer);
		size = strlen(buffer);
		memset(digit, 0, sizeof(digit));
		for(int i = 0; i < size; ++ i){
			digit[i] = buffer[size - 1 - i] - '0';
		}
	}
	
	void increase(){
		int delta = 1;
		for(int i = 0; i < size; ++ i){
			delta += digit[i];
			digit[i] = delta % 10;
			delta /= 10;
		}
		if(delta > 0){
			digit[size ++] = delta;
		}
		/*	
		printf("%d\n", size);
		for(int i = size - 1; i > -1; -- i){
			printf("%d", digit[i]);
		}
		printf("\n");
		*/
	}
};

int t, k, dp[N + 1][N + 1][2];
Integer l, r;

void update(int &x, long long a){
	x = (x + a) % MOD;
}

bool isLucky(int x){
	return x == 4 || x == 7;
}

int count(const Integer &n){
	int result = 0;
	for(int i = 0; i < n.size - 1; ++ i){
		for(int j = 1; j <= 9; ++ j){
			if(isLucky(j)){
				update(result, dp[i][k - 1][0]);
			}
			update(result, dp[i][k][1]);
//			printf("%d %d %d\n", i, j, result);
		}
	}
//	printf("===\n");
//	printf("%d\n", result);
	int last = k;
	bool succ = false;
	for(int i = n.size - 1; i > -1; -- i){
		for(int j = 0; j < n.digit[i]; ++ j){
			if(i == n.size - 1 && j == 0){
				continue;
			}
			if(succ || (isLucky(j) && last < k)){
				update(result, dp[i][k][0]);
			}else{
				int temp = isLucky(j)? 0: last + 1;
				if(temp < k){
					update(result, dp[i][k - 1 - temp][0]);
				}
			}
			update(result, dp[i][k][1]);
//			printf("%d %d %d\n", i, j, result);
		}
		succ |= isLucky(n.digit[i]) && last < k;
		last = isLucky(n.digit[i])? 0: min(last + 1, k);
	}
	return result;
}

int main(){
	scanf("%d%d", &t, &k);
	memset(dp, 0, sizeof(dp));
	dp[0][k][0] = 1;
	for(int i = 0; i < N; ++ i){
		for(int j = 0; j <= k; ++ j){
			update(dp[i + 1][0][j < k], dp[i][j][0] * 2LL);
			update(dp[i + 1][min(j + 1, k)][0], dp[i][j][0] * 8LL);
			update(dp[i + 1][0][1], dp[i][j][1] * 2LL);
			update(dp[i + 1][min(j + 1, k)][1], dp[i][j][1] * 8LL);
		}
	}
	for(int i = 0; i <= N; ++ i){
		for(int j = 1; j <= k; ++ j){
			update(dp[i][j][0], dp[i][j - 1][0]);
			update(dp[i][j][1], dp[i][j - 1][1]);
		}
	}
	while(t --){
		l.initialize();
		r.initialize();
		r.increase();
//		printf("%d\n", count(r));
		printf("%d\n", (count(r) - count(l) + MOD) % MOD);
	}
	return 0;
}