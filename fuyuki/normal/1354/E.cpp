#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=5e3+1;
int n,m,tot,n1,n2,n3,cnt[2];
int siz,t[N],dfn[N],co[N],a[N],b[N],out[N];
int f[N][N],ans[N],id[N];
vector<int>e[N];
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V dfs(int u,int p){
	dfn[u]=1,cnt[co[u]=p]++,id[u]=tot;
	for(int v:e[u])
		if(dfn[v]){
			if(co[v]==p)
				cout<<"NO\n",exit(0);
		}
		else dfs(v,p^1);
}
V solve(int u,int p){
	dfn[u]=0;
	if(co[u]==p)co[u]=2;
	else if(n1)n1--,co[u]=1;
	else co[u]=3;
	for(int v:e[u])if(dfn[v])
		solve(v,p);
}
int main(){
//	freopen("test.in","r",stdin);
	n=getint(),m=getint(),f[0][0]=1;
	n1=getint(),n2=getint(),n3=getint();
	for(int x,y;m--;add_edge(x,y))x=getint(),y=getint();
	FOR(i,1,n)if(!dfn[i]){
		cnt[0]=cnt[1]=0,tot++,dfs(i,0);
		a[tot]=cnt[0],b[tot]=cnt[1];
		ROF(j,n,0)FOR(k,0,1)
			f[tot][j]|=cnt[k]<=j&&f[tot-1][j-cnt[k]];
	}
	if(!f[tot][n2])cout<<"NO\n",exit(0);
	while(tot){
		FOR(i,1,n)if(id[i]==tot){
			if(a[tot]<=n2&&f[tot-1][n2-a[tot]])
				n2-=a[tot],solve(i,0);
			else
				n2-=b[tot],solve(i,1);
			goto end;
		}
		end:tot--;
	}
	cout<<"YES\n";
	FOR(i,1,n)cout<<co[i];
	return 0;
}