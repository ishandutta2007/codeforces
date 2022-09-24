#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=1000,mod=998244353,BB=400;
int n,q,dfn[150005],sz[150005],sign=0;
int bel[150005];
ll a[150005],b[150005],tag[150005],vt[150005];
vector<int> g[150005],val[150005];
void dfs(int x,int f){
	dfn[x]=++sign,sz[x]=1;
	for(int y:g[x]){
		if(y==f)continue;
		dfs(y,x),sz[x]+=sz[y];
	}
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
void dfs2(int x,int f,int fr,int v){
	val[fr][x]=v;
	for(int y:g[x]){
		if(y==f)continue;
		if(x!=fr)dfs2(y,x,fr,v);
		else if(dfn[y]>dfn[x])dfs2(y,x,fr,n-sz[y]);
		else dfs2(y,x,fr,sz[x]);
	}
}
void Add(int x,ll y){
	if(x>n)return ;
	vt[x]+=y,tag[bel[x]]+=y;
}
ll Query(int x){
	int z=x;
	ll sum=0;
	for(;bel[z]==bel[x];z--)sum+=vt[z];
	z=bel[z];
	for(;z;z--)sum+=tag[z];
	return sum;
}
int main() {
	cin>>n>>q;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<=n;i++)bel[i]=(i-1)/BB+1;
	vector<int> bigd;
	for(int i=1;i<=q;i++){
		if(g[i].size()>B){
			val[i].resize(n+1);
			dfs2(i,0,i,0);
			bigd.push_back(i);
		}
	}
	for(int i=1,op,x,y;i<=q;i++){
		scanf("%d%d",&op,&x);
		if(op==1){
			scanf("%d",&y);
			b[x]+=1ll*y*n;
			if(g[x].size()>B){
				a[x]+=y;
			}
			else {
				for(int z:g[x]){
					if(dfn[z]>dfn[x]){
						Add(dfn[z],1ll*y*(n-sz[z]));
						Add(dfn[z]+sz[z],-1ll*y*(n-sz[z]));
					}
					else {
						Add(1,1ll*y*sz[x]);
						Add(dfn[x],-1ll*y*sz[x]);
						Add(dfn[x]+sz[x],1ll*y*sz[x]);
					}
				}
			}
		}
		else {
			ll sum=0;
			sum+=b[x];
			sum+=Query(dfn[x]);
			for(int j:bigd){
				if(j==x)continue;
				sum+=val[j][x]*a[j];
			}
			sum%=mod;
			cout<<1ll*sum*Power(n,mod-2)%mod<<'\n';
		}
	}
}