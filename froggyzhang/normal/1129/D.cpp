#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int mod=998244353;
typedef long long ll;
int n,m,a[N],dp[N],las[N],jb[N];
class Block{
	#define B 360
	int len,blocks,L[N],R[N],pos[N],g[N],tadd[N],val[B][B],pre[B][B],cnt[B];
public:
	void init(int n){
		len=sqrt(n);
		blocks=n/len;
		if(n%len)++blocks;
		for(int i=1;i<=blocks;++i){
			L[i]=(i-1)*len+1;
			R[i]=min(n,i*len);
			for(int j=L[i];j<=R[i];++j)pos[j]=i;
			cnt[i]=1;
		}	
	}
	void Renew(int x){
		if(tadd[x]){
			for(int i=L[x];i<=R[x];++i)g[i]+=tadd[x];
			tadd[x]=0;
		}	
	}
	void rebuild(int x){
		static int V[N],c[N],tot;
		tot=0;
		for(int i=L[x];i<=R[x];++i){
			V[++tot]=g[i];
			c[g[i]]=(c[g[i]]+dp[i-1])%mod;
		}
		sort(V+1,V+tot+1);
		tot=unique(V+1,V+tot+1)-V-1;
		cnt[x]=tot;
		for(int i=1;i<=tot;++i){
			val[x][i]=V[i];
			pre[x][i]=(pre[x][i-1]+c[V[i]])%mod;	
		}
		for(int i=1;i<=tot;++i){
			c[V[i]]=0;
		}
	}
	void Add(int l,int r,int d){
		if(l>r)return;
		int x=pos[l],y=pos[r];	
		if(x==y){
			Renew(x);
			for(int i=l;i<=r;++i)g[i]+=d;
			rebuild(x);
		}
		else{
			Renew(x);
			for(int i=l;i<=R[x];++i)g[i]+=d;
			for(int i=x+1;i<y;++i){
				tadd[i]+=d;	
			}
			Renew(y);
			for(int i=L[y];i<=r;++i)g[i]+=d;
			rebuild(x),rebuild(y);
		}
	}
	void Insert(int i){
		int x=pos[i];
		Renew(x);
		rebuild(x);	
	}
	int Query(int r){
		int x=pos[r],ans=0;
		for(int i=1;i<x;++i){
			int z=upper_bound(val[i]+1,val[i]+cnt[i]+1,m-tadd[i])-val[i]-1;
			ans=(ans+pre[i][z])%mod;
		}
		Renew(x);
		for(int i=L[x];i<=r;++i){
			if(g[i]+tadd[i]<=m)ans=(ans+dp[i-1])%mod;	
		}
		return ans;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	T.init(n);
	dp[0]=1;
	for(int i=1;i<=n;++i){
		las[i]=jb[a[i]];
		jb[a[i]]=i;
		T.Insert(i);
		T.Add(las[las[i]]+1,las[i],-1);
		T.Add(las[i]+1,i,1);
		dp[i]=T.Query(i);
	}
	cout<<dp[n]<<'\n';
	return 0;
}