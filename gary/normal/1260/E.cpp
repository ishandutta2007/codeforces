#include <bits/stdc++.h>

using namespace std;

const int LOGN = 20;
const int N = (1 << LOGN) + 99;
const long long INF = 1e18;

int n;
int a[N];
long long dp[LOGN+2][N];
int sum[100];

long long calc(int cnt, int pos){
	long long &res = dp[cnt][pos];
	if(res != -1) return res;

	if(a[pos] == -1) return res = 0;
	int rem = sum[cnt] - pos;

	res = INF;
	if(cnt < LOGN)
		res = calc(cnt + 1, pos + 1) + a[pos];
	if(rem > 0)		
		res = min(res, calc(cnt, pos + 1));

	return res;
}

int main() {	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for(int i = 1, x = n / 2; i < 100; ++i, x /= 2)
		sum[i] = sum[i - 1] + x;
	
	reverse(a, a + n);
	memset(dp, -1, sizeof dp);
	printf("%lld", calc(0, 0));	
	return 0;
}