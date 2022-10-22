#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
using namespace std;
typedef long long ll;
constexpr int N=100005;
int n,m,k,tot,top,p[N],dfn[N],dep[N],st[N],F[N][21];bool qr[N];
vector<int>G[N],E[N];
inline void rd(int &x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
inline void dfs(int x,int fa){
	dfn[x]=++tot,dep[x]=dep[fa]+1,F[x][0]=fa;
	for(auto y:G[x])if(y^fa)dfs(y,x);
}
inline int dp(int x){
	int sum=0,ones=0;
	for(auto y:E[x])sum+=dp(y),ones+=qr[y],qr[y]=0;
	if(qr[x])sum+=ones;
	else if(ones>1)++sum;
	else if(ones)qr[x]=1;
	return sum;
}
inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	rep(i,0,20)if(dep[x]-dep[y]>>i&1)x=F[x][i];
	if(x==y)return x;
	per(i,20,0)if(F[x][i]^F[y][i])x=F[x][i],y=F[y][i];
	return F[x][0];
}
int main(){
	rd(n);
	rep(i,2,n){
		int u,v,w;rd(u),rd(v);
		G[u].eb(v),G[v].eb(u);
	}
	dfs(1,0);
	rep(j,1,20)rep(i,1,n)F[i][j]=F[F[i][j-1]][j-1];
	for(rd(m);m--;){
		rd(k);rep(i,1,k)rd(p[i]),qr[p[i]]=1;
		int fl=0;
		rep(i,1,k)if(qr[F[p[i]][0]]){fl=1;break;}
		if(fl){puts("-1");goto NXT;}
		sort(p+1,p+1+k,[&](int x,int y){return dfn[x]<dfn[y];});
		st[top=1]=1,E[1].clear();
		rep(i,1,k)if(p[i]^1){
			int l=lca(st[top],p[i]);
			if(l^st[top]){
				while(dfn[l]<dfn[st[top-1]])
					E[st[top-1]].eb(st[top]),--top;
				if(l==st[top-1])E[l].eb(st[top]),--top;
				else E[l].clear(),E[l].eb(st[top]),st[top]=l;
			}
			E[p[i]].clear(),st[++top]=p[i];
		}
		rep(i,1,top-1)E[st[i]].eb(st[i+1]);
		printf("%d\n",dp(1));
		NXT:;rep(i,1,k)qr[p[i]]=0;qr[1]=0;
	}
	return 0;
}