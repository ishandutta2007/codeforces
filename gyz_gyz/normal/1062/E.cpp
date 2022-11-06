#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,m,tot,f[N][18],id[N],h[N];
vector<int>p[N];
struct pp{int m1,m2,M1,M2;}a[N*2];
pp operator +(pp x,pp y){pp r;
	if(id[x.m1]<id[y.m1]){r.m1=x.m1;
		if(x.m2&&id[x.m2]<id[y.m1])r.m2=x.m2;else r.m2=y.m1;
	}else{r.m1=y.m1;
		if(y.m2&&id[y.m2]<id[x.m1])r.m2=y.m2;else r.m2=x.m1;
	}
	if(id[x.M1]>id[y.M1]){r.M1=x.M1;
		if(x.M2&&id[x.M2]>id[y.M1])r.M2=x.M2;else r.M2=y.M1;
	}else{r.M1=y.M1;
		if(y.M2&&id[y.M2]>id[x.M1])r.M2=y.M2;else r.M2=x.M1;
	}return r;
}
void dfs(int x){id[x]=++tot;
	for(auto i:p[x]){
		h[i]=h[x]+1;dfs(i);
	}
}
int lca(int x,int y){
	if(h[x]<h[y])swap(x,y);
	dep(i,17,0)if((h[x]-h[y])>>i)x=f[x][i];
	dep(i,17,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	if(x!=y)x=f[x][0],y=f[y][0];return x;
}
void bt(int x,int l,int r){
	if(l==r){a[x].m1=a[x].M1=l;return;}
	int rr=(l+r)/2;bt(x*2,l,rr);bt(x*2+1,rr+1,r);
	a[x]=a[x*2]+a[x*2+1];
}
pp q(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return a[x];int rr=(L+R)/2;
	if(r<=rr)return q(x*2,l,r,L,rr);
	if(l>rr)return q(x*2+1,l,r,rr+1,R);
	return q(x*2,l,rr,L,rr)+q(x*2+1,rr+1,r,rr+1,R);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,2,n){
		scanf("%d",&f[i][0]);
		p[f[i][0]].pb(i);
	}
	dfs(1);bt(1,1,n);
	rep(j,1,17)rep(i,1,n)f[i][j]=f[f[i][j-1]][j-1];
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		pp t=q(1,x,y,1,n);
		int t1=lca(t.m2,t.M1);int t2=lca(t.m1,t.M2);
		if(h[t1]<h[t2])printf("%d %d\n",t.M1,h[t2]);
		else printf("%d %d\n",t.m1,h[t1]);
	}
}