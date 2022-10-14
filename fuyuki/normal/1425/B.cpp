#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a,i##end=b;i<=i##end;i++) 
#define ROF(i,a,b) for(int i=a,i##end=b;i>=i##end;i--) 
using namespace std;
typedef long long ll;
const int N=2010,M=4010,mod=1e9+7,O=2000;
int pf[N][M],sf[N][M],pg[N][M],sg[N][M];
int fst[M],nxt[M+M],u[M+M],v[M+M],tot;
int vis[N],len[N],cl,n,m,ans;
int read()
{
	int res=0,fl=0; char a=getchar();
	while(a<'0'||a>'9') {if(a=='-') fl=1;a=getchar();}
	while(a>='0'&&a<='9') res=res*10+a-'0',a=getchar();
	return fl? -res:res;
}
void ad(int lu,int lv)
{
	u[++tot]=lu,v[tot]=lv,nxt[tot]=fst[lu],fst[lu]=tot;
	u[++tot]=lv,v[tot]=lu,nxt[tot]=fst[lv],fst[lv]=tot;
}
void dfs(int lx,int zs) {vis[lx]=1,len[zs]++; for(int i=fst[lx];i;i=nxt[i]) if(!vis[v[i]]) dfs(v[i],zs);}
void add(int &a,int b) {a=(a+b)%mod;}
int ask(int *f,int *g,int b)
{
	int res=0;
	FOR(i,-n,n) if(b-i>=-n&&b-i<=n) add(res,2ll*f[i+O]*g[b-i+O]%mod);
	return res;
}
int main()
{
	n=read(),m=read(),vis[1]=1;
	FOR(i,1,m) ad(read(),read());
	for(int i=fst[1];i;i=nxt[i]) if(!vis[v[i]]) len[++cl]=1,dfs(v[i],cl);
	pf[0][O]=pg[0][O]=1;
	FOR(i,0,cl-1) FOR(j,O-n,O+n) if(pf[i][j]||pg[i][j])
		add(pf[i+1][j],pf[i][j]),add(pf[i+1][j-len[i+1]],pf[i][j]),add(pf[i+1][j+len[i+1]],pf[i][j]),\
		add(pg[i+1][j-len[i+1]],pg[i][j]),add(pg[i+1][j+len[i+1]],pg[i][j]);
	sf[cl+1][O]=sg[cl+1][O]=1,add(ans,pg[cl][O]);
	ROF(i,cl+1,2) FOR(j,O-n,O+n) if(sf[i][j]||sg[i][j])
		add(sf[i-1][j],sf[i][j]),add(sf[i-1][j-len[i-1]],sf[i][j]),add(sf[i-1][j+len[i-1]],sf[i][j]),\
		add(sg[i-1][j-len[i-1]],sg[i][j]),add(sg[i-1][j+len[i-1]],sg[i][j]);
	FOR(i,1,cl) FOR(j,-len[i]+2,len[i]-2) add(ans,ask(pf[i-1],sf[i+1],j));
	FOR(i,1,cl) add(ans,ask(pg[i-1],sg[i+1],len[i]-1)),add(ans,ask(pg[i-1],sg[i+1],1-len[i]));
	cout<<ans;
	return 0;
}