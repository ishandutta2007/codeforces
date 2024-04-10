#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100,mod=1e9+7,maxn=2e5;
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

vector<int> B[N];bool bk[N];int fl[N],nf[N],si[N],fa[N];
int C(int n,int m){
	if(n<m) return 0;
	return (ll)fl[n]*nf[m]%mod*nf[n-m]%mod;
}

int Ans=0,n,K;
void dfs(int x){
	bk[x]=false;si[x]=1;
	for(auto y:B[x]){
		if(bk[y]){
			fa[y]=x;
			dfs(y);
			si[x]+=si[y]; 
		}
	}
	int Sum=0;
	for(auto y:B[x])
		if(fa[y]==x){
			Sum=(Sum+C(si[y],K))%mod;
		}
	Sum=(Sum+C(n-si[x],K))%mod;
	
	for(auto y:B[x])
		if(fa[y]==x){
			int t=(Sum-C(si[y],K)+mod)%mod;
			Ans=(Ans+(ll)(C(n-si[y],K)-t+mod)*si[y]%mod*(n-si[y]))%mod;
		}
	int t=(Sum-C(n-si[x],K)+mod)%mod;
	Ans=(Ans+(ll)(C(si[x],K)-t+mod)*(n-si[x])%mod*si[x])%mod;
	Ans=(Ans+(ll)(C(n,K)-Sum+mod)*n)%mod;
}

int main()
{
	
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	scanf("%d%d",&n,&K);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		B[x].push_back(y);
		B[y].push_back(x);
	}
	
	memset(bk,true,sizeof(bk));
	dfs(1); 
	
	printf("%d\n",Ans);
	
	return 0;
}