#include<bits/stdc++.h>
using namespace std;
#define N 1005
const int mod=998244353;
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
int a[N],n,m,L[N],R[N],mn[N][N],dp[N][N],g[N];
vector<int> p[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		a[i]=read();
		if(a[i]==a[i-1]){
			--m,--i;continue;
		}
		if(i>2*n)return !printf("0\n");
	}
	memset(L,0x3f,sizeof(L));
	for(int i=1;i<=m;++i){
		L[a[i]]=min(L[a[i]],i);
		R[a[i]]=max(R[a[i]],i);
		p[a[i]].push_back(i);
	}
	for(int i=1;i<=m;++i){
		mn[i][i]=a[i];
		for(int j=i+1;j<=m;++j)mn[i][j]=min(mn[i][j-1],a[j]);
	}
	for(int i=0;i<=m;++i)dp[i+1][i]=1;
	for(int len=1;len<=m;++len){
		for(int l=1;l+len-1<=m;++l){
			int r=l+len-1;
			int x=mn[l][r];
			if(L[x]<l||R[x]>r)continue;
			if(L[x]==l&&R[x]==r){
				g[x]=1;
				for(int i=0;i<(int)p[x].size()-1;++i){
					g[x]=1LL*g[x]*dp[p[x][i]+1][p[x][i+1]-1]%mod;
				}
			}
			int wl=0,wr=0;
			for(int i=L[x];i>=l;--i){
				wl=(wl+1LL*dp[l][i-1]*dp[i][L[x]-1])%mod;	
			}
			for(int j=R[x];j<=r;++j){
				wr=(wr+1LL*dp[R[x]+1][j]*dp[j+1][r])%mod;			
			}
			dp[l][r]=1LL*g[x]*wl%mod*wr%mod;
		}
	}
	printf("%d\n",dp[1][m]);
	return 0;
}