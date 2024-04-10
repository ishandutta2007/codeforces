#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=5e5+2,INF=0x3f3f3f3f;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const char st[10]="RDLU";
int T,n,m,tot,now;
int lk[N],kl[N],dfn[N];
vector<int>a[N],e[N],b[N],c[N];
I id(int x,int y){return (x-1)*m+y;}
V input(){
	n=getint(),m=getint(),tot=n*m;
	FOR(i,1,n)b[i].clear(),c[i].clear(),a[i].clear();
	FOR(i,1,n)a[i].resize(m+1),b[i].resize(m+1),c[i].resize(m+1);
	FOR(i,1,n)FOR(j,1,m)a[i][j]=getint();
}
I valid(int x,int y){return 1<=x&&x<=n&&1<=y&&y<=m;}
V init(int tx=0,int ty=0){
	now=0;
	FOR(i,1,tot*3)e[i].clear(),dfn[i]=lk[i]=kl[i]=0;
	FOR(x,1,n)FOR(y,1,m)FOR(i,0,3)
		if(valid(tx=x+dx[i],ty=y+dy[i])&&a[x][y]==a[tx][ty]){
			e[id(x,y)].push_back(id(tx,ty));
//			cout<<x<<' '<<y<<' '<<tx<<' '<<ty<<'\n';
		}
}
I dfs0(int u){
	if(dfn[u]==now)return 0;
	dfn[u]=now;
	for(int v:e[u])if(!kl[v]||dfs0(kl[v]))
		return kl[v]=u,lk[u]=v,1;
	return 0;
}
I dfs1(int u){
	if(dfn[u]==now)return 0;
	dfn[u]=now;
	for(int v:e[u])if(!lk[v]||dfs1(lk[v]))
		return lk[v]=u,kl[u]=v,1;
	return 0;
}
V work(){
	int tx,ty,cnt,u,v;
	FOR(x,1,n)FOR(y,1,m){
		cnt=0,u=id(x,y);
		FOR(i,0,3)if(valid(tx=x+dx[i],ty=y+dy[i]))
			cnt+=a[tx][ty]<a[x][y];
		if(cnt){
			if(x+y&1)e[u].push_back(u+tot),e[u+tot].push_back(u);
			else e[u].push_back(u+tot+tot),e[u+tot+tot].push_back(u);
		}
	}
	FOR(x,1,n)FOR(y,1,m){
		cnt=0,u=id(x,y);
		FOR(i,0,3)if(valid(tx=x+dx[i],ty=y+dy[i]))
			cnt+=a[tx][ty]<a[x][y];
		if(!cnt){
			if(x+y&1){
				if(!lk[u]&&++now&&!dfs0(u))
					return void(cout<<"NO\n");
			}
			else{
				if(!kl[u]&&++now&&!dfs1(u))
					return void(cout<<"NO\n");
			}
		}
	}
	cout<<"YES\n";
	FOR(x,1,n)FOR(y,1,m){
		u=id(x,y);
		if(x+y&1){
			if(lk[u]&&lk[u]<=tot){
				FOR(i,0,3)if(valid(tx=x+dx[i],ty=y+dy[i])&&id(tx,ty)==lk[u]){
					if(!b[tx][ty])b[x][y]=1;
					else b[x][y]=a[x][y]-1;
					c[x][y]=i;break;
				}
				continue;
			}
		}
		else{
			if(kl[u]&&kl[u]<=tot){
				FOR(i,0,3)if(valid(tx=x+dx[i],ty=y+dy[i])&&id(tx,ty)==kl[u]){
					if(!b[tx][ty])b[x][y]=1;
					else b[x][y]=a[x][y]-1;
					c[x][y]=i;break;
				}
				continue;
			}
		}
		FOR(i,0,3)if(valid(tx=x+dx[i],ty=y+dy[i])&&a[tx][ty]<a[x][y]){
			b[x][y]=a[x][y]-a[tx][ty],c[x][y]=i;break;
		}
	}
	FOR(i,1,n)FOR(j,1,m)cout<<b[i][j]<<" \n"[j==m];
	FOR(i,1,n)FOR(j,1,m)cout<<st[c[i][j]]<<" \n"[j==m];
//	cerr<<T<<'\n';
//	FOR(x,1,n)FOR(y,1,m)FOR(i,0,3)if(i==c[x][y]){
//		tx=x+dx[i],ty=y+dy[i];
//		if(a[tx][ty]==a[x][y])
//			assert(abs(i-c[tx][ty])==2&&b[x][y]+b[tx][ty]==a[x][y]);
//		else assert(b[x][y]==a[x][y]-a[tx][ty]);
//	}
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}