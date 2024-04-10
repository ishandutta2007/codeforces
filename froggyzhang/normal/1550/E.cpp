#include<bits/stdc++.h>
using namespace std;
#define N 200010
const int inf=0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;
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
int n,K,a[N],nxt[17][N],h[17][N],g[N],dp[1<<17];
char s[N];
bool check(int x){
	memset(nxt,0x3f,sizeof(nxt));
	memset(dp,0x3f,sizeof(dp));
	for(int j=0;j<K;++j){
		int las=-1;
		for(int i=x;i<=n;++i){
			if(h[j][i]-h[j][i-x]==g[i]-g[i-x]){
				for(int k=las+1;k<=i-x;++k)nxt[j][k]=i;
				las=i-x;	
			}
		}
	}
	dp[0]=0;
	for(int i=1;i<(1<<K);++i){
		for(int j=0;j<K;++j){
			if(i>>j&1){
				if(dp[i^(1<<j)]^inf)
					dp[i]=min(dp[i],nxt[j][dp[i^(1<<j)]]);
			}
		}
	}
	return dp[(1<<K)-1]^inf;
}
int main(){
	n=read(),K=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='?')a[i]=-1;
		else a[i]=s[i]-'a';
	}
	for(int j=0;j<K;++j){
		for(int i=1;i<=n;++i){
			h[j][i]=h[j][i-1]+(a[i]==j);	
		}
	}
	for(int i=1;i<=n;++i){
		g[i]=g[i-1]+(a[i]>=0);	
	}
	int l=1,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,l=mid+1;
		}
		else{
			r=mid;
		}	
	}
	printf("%d\n",ans);
	return 0;
}