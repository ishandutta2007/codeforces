#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
const int mod=998244353;
int n,D[N],a[N][N],pw[N],ans,fac[N],c[N][N];
class BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
public:
	void Clear(){memset(b,0,sizeof(b));}
	void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B1,B2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	D[0]=1;
	for(int i=2;i<=n;++i){
		D[i]=1LL*(i-1)*(D[i-1]+D[i-2])%mod;
	}
	pw[0]=fac[0]=1;
	for(int i=1;i<=n;++i){
		pw[i]=1LL*pw[i-1]*D[n]%mod;
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	for(int j=0;j<=n;++j){
		c[0][j]=fac[j];
	}
	for(int i=1;i<=n;++i){
		c[i][0]=D[i];
		for(int j=1;i+j<=n;++j){
			c[i][j]=(1LL*c[i][j-1]*(i+j)+1LL*c[i-1][j-1]*i)%mod;
		}	
	}
	for(int i=1;i<=n;++i){
		static int vis[N],d[N];
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		int A=0,B=n;
		B1.Clear(),B2.Clear();
		// B1: d[i]==0
		// B2: d[i]==1
		for(int j=1;j<=n;++j){
			B1.Add(j,1);
		}
		for(int j=1;j<=n;++j){
			int c1=B1.Ask(a[i][j]-1);
			int c2=B2.Ask(a[i][j]-1);
			if(i>1&&!vis[a[i-1][j]]&&a[i-1][j]<a[i][j]){
				if(d[a[i-1][j]])--c2;
				else --c1;
			}
			int u=a[i-1][j];
			int v=a[i][j];
			if(i==1){
				ans=(ans+1LL*pw[n-i]*fac[n-j]%mod*c1)%mod;	
			}
			else{
				int nA=A-1+(!d[u]);
				int nB=B-(!d[u]);
				ans=(ans+1LL*pw[n-i]*c[nB][nA]%mod*c2)%mod;
				++nA,--nB;
				ans=(ans+1LL*pw[n-i]*c[nB][nA]%mod*c1)%mod;
			}
			/*
			for(int k=1;k<a[i][j];++k){
				if(vis[k]||k==a[i-1][j])continue;
				if(i==1){
					ans=(ans+1LL*pw[n-i]*fac[n-j])%mod;	
				}	
				else{
					int u=a[i-1][j];
					int nA=A-1+(!d[u])+(!d[k]);
					int nB=B-(!d[u])-(!d[k]);
					ans=(ans+1LL*pw[n-i]*c[nB][nA])%mod;
				}
			}
			*/	
			vis[a[i][j]]=1;
			if(d[v])B2.Add(v,-1);
			else B1.Add(v,-1);
			if(i>1){	
				if(!d[u])++A,--B;
				if(!d[v])++A,--B;
				--A;
				if(!d[u])B1.Add(u,-1),B2.Add(u,1);
				++d[u],++d[v];
			}
		}	
	}
	cout<<ans<<'\n';
	return 0;
}