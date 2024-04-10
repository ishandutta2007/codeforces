#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n;
ll ans,dp[N][11];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		int x=s[i]-'0';
		if(x)++dp[i][x];
		for(int j=x+1;j<=10;++j){
			dp[i][(j*(j-1)/2+x+10)%11]+=dp[i-1][j];	
		}
		for(int j=0;j<=10;++j)ans+=dp[i][j];
	}
	printf("%lld\n",ans);
	return 0;
}