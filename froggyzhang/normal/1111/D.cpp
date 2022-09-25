#include<bits/stdc++.h>
using namespace std;
#define N 100050
const int mod=1e9+7;
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
int dp[N>>1],n,cnt[52],fac[N],ifac[N],H,g[N>>1],ans[52][52],Q;
char s[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int Get(char c){
	if(c>='a'&&c<='z')return c-'a';
	return c-'A'+26;
}
void tui(int *dp,int x){
	for(int i=x;i<=(n>>1);++i){
		dp[i]=(dp[i]-dp[i-x]+mod)%mod;
	}	
}
void ins(int *dp,int x){
	for(int i=(n>>1);i>=x;--i){
		dp[i]=(dp[i]+dp[i-x])%mod;		
	}
}
int main(){
	scanf("%s",s+1);
	Q=read();
	n=strlen(s+1);
	init(n);
	for(int i=1;i<=n;++i){
		++cnt[Get(s[i])];
	}
	H=1LL*fac[n>>1]*fac[n>>1]%mod;
	for(int i=0;i<52;++i){
		H=1LL*H*ifac[cnt[i]]%mod;
	}
	dp[0]=1;
	for(int i=0;i<52;++i){
		if(cnt[i])ins(dp,cnt[i]);
	}
	memset(ans,-1,sizeof(ans));
	while(Q--){
		int x=Get(s[read()]),y=Get(s[read()]);
		if(x<y)swap(x,y);
		if(!~ans[x][y]){
			if(x==y){
				ans[x][y]=1LL*H*dp[n>>1]%mod;
			}
			else{
				memcpy(g,dp,sizeof(g));
				tui(g,cnt[x]);
				tui(g,cnt[y]);
				ins(g,cnt[x]+cnt[y]);
				ans[x][y]=1LL*H*g[n>>1]%mod;
			}
		}
		printf("%d\n",ans[x][y]);
	}
	return 0;
}