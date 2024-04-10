#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 300000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,m,tot;vector<int>p[N];set<pr>se;
int f[N][19],h[N],id[N],rt[N],a[N*2],b[N*2],lz[N*2];
void init(int x,int l,int r){
	b[x]=r-l+1;if(b[x]==1)return;int rr=(l+r)/2;
	init(x*2,l,rr);init(x*2+1,rr+1,r);
}
void cg(int x,int l,int r,int y,int L,int R){
	if(l<=L&&r>=R){a[x]+=y,lz[x]+=y;return;}
	int rr=(L+R)/2;a[x*2]+=lz[x];a[x*2+1]+=lz[x];
	lz[x*2]+=lz[x];lz[x*2+1]+=lz[x];lz[x]=0;
	if(l<=rr)cg(x*2,l,r,y,L,rr);
	if(r>rr)cg(x*2+1,l,r,y,rr+1,R);
	a[x]=min(a[x*2],a[x*2+1]);
	b[x]=b[x*2]*(a[x]==a[x*2])+b[x*2+1]*(a[x]==a[x*2+1]);
}
void dfs(int x){id[x]=++tot;
	for(auto i:p[x])if(i!=f[x][0]){
		f[i][0]=x;h[i]=h[x]+1;dfs(i);
	}rt[x]=tot;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	f[1][0]=1;dfs(1);init(1,1,n);
	rep(j,1,18)rep(i,1,n)f[i][j]=f[f[i][j-1]][j-1];
	rep(i,1,m){int x,y,z;
		scanf("%d%d",&x,&y);
		if(id[x]>id[y])swap(x,y);
		if(se.count({x,y})){
			se.erase({x,y});z=-1;
		}else{
			se.insert({x,y});z=1;
		}
		if(rt[x]>=id[y]){
			cg(1,id[y],rt[y],-z,1,n);
			dep(j,18,0)if((h[y]-h[x]-1)>>j)y=f[y][j];
			cg(1,id[y],rt[y],z,1,n);
		}else{
			cg(1,1,n,z,1,n);
			cg(1,id[x],rt[x],-z,1,n);
			cg(1,id[y],rt[y],-z,1,n);
		}
		if(!a[1])printf("%d\n",b[1]);else printf("0\n");
	}
}