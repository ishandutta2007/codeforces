#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define N 1010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int dp[N][N][26],n,m,ans;
char a[N],b[N];
int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	#define update(x,y) x=(x+y)%mod
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int k=0;k<26;++k){
				if(i&&a[i]-'a'!=k)update(dp[i][j][a[i]-'a'],dp[i-1][j][k]);
				if(j&&b[j]-'a'!=k)update(dp[i][j][b[j]-'a'],dp[i][j-1][k]);
			}
			if(i)++dp[i][j][a[i]-'a'];
			if(j)++dp[i][j][b[j]-'a'];
			for(int k=0;k<26;++k){
				ans=(ans+dp[i][j][k])%mod;
			}	
		}
	}
	for(int i=1,las=0;i<=n;++i){
		if(i==n||a[i]==a[i+1]){
			ans=(ans-1LL*(i-las)*(i-las+1)/2*(m+1)%mod+mod)%mod;
			las=i;	
		}
	}
	for(int i=1,las=0;i<=m;++i){
		if(i==m||b[i]==b[i+1]){
			ans=(ans-1LL*(i-las)*(i-las+1)/2*(n+1)%mod+mod)%mod;
			las=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}