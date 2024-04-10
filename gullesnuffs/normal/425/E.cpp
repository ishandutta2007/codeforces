#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
#define MOD 1000000007
using namespace std;

long long psum[505][505];
int pw[1000000];
int dp[505][505];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	if(!k){
		printf("1\n");
		return 0;
	}
	pw[0]=1;
	for(int i=1; i < 1000000; ++i)
		pw[i]=(pw[i-1]*2)%MOD;
	for(int i=0; i < 505; ++i)
		for(int j=1; j < i; ++j){
			int s=0;
			for(int k=1; k <= i-j; ++k){
				s=(s+pw[(i-j)*j+(k-1)])%MOD;
			}
			psum[i][j]=s;
		}
	for(int p=0; p < n; ++p){
		dp[p][1]=(pw[p+1]+MOD-1)%MOD;
	}
	for(int p=1; p < n; ++p)
		for(int i=2; i <= k; ++i){
			int s=0;
			for(int j=p-1; j >= 0; --j){
				s=(s+dp[j][i-1]*psum[p+1][j+1])%MOD;
			}
			dp[p][i]=s;
		}
	long long ans=0;
	for(int p=0; p < n; ++p){
		long long tmp=dp[p][k];
		ans=(ans+tmp*pw[(n-p-1)*(p+1)])%MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}