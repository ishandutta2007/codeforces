#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
LL cnt[5005];
LL dp[5005][5005];
int mod=998244353;
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
LL fra[50005];
void build(){
	fra[0]=1;
	for(int i = 1;i<50005;i++)
	fra[i] = fra[i-1]*i%mod;
}
int main(){
	build();
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	dp[0][0]=1;
	LL ans=0;
	LL mon=1;
	for(int i  =1;i<=n;i++)
		mon=mon*i%mod;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<i;j++){
			if(n-2-j>=0){
				ans += dp[i-1][j]*cnt[i]%mod*(cnt[i]-1)%mod*fra[n-2-j]%mod;
				ans%=mod;
			}
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
			dp[i][j+1]+=dp[i-1][j]*cnt[i]%mod;
			dp[i][j+1]%=mod;
		}
	}
	printf("%lld\n",ans*f_pow(mon,mod-2)%mod);
}
/*

2*5!     240
2*4!*5   240
2*3!*10 120
2*2!*10 40
2*1!*5  10
2    2

*/