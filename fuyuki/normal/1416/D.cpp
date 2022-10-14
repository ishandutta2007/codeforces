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
set<int>mp[N];
int T,n,m,q,ans;
int w[N],a[N],b[N],id[N];
int fa[N],siz[N],tag[N];
int opt[N],val[N],dis[N][2];
vector<int>now[N];
V input(){
	n=getint(),m=getint(),q=getint();
	FOR(i,1,n)w[i]=getint(),id[w[i]]=i;
	FOR(i,1,m)a[i]=getint(),b[i]=getint(),tag[i]=1;
	FOR(i,1,q)opt[i]=getint(),val[i]=getint();
}
V merge(int x,int y){
	if((x=fa[x])==(y=fa[y]))return;
	if(siz[x]<siz[y])swap(x,y);
	for(int v:now[y])now[x].push_back(v),fa[v]=x;
	siz[x]+=siz[y];
}
V init(int x=0,int y=0){
	FOR(i,1,n)fa[i]=i,siz[i]=1,now[i].push_back(i);
	FOR(i,1,q)if(opt[i]==2)tag[val[i]]=0;
	FOR(i,1,m)if(tag[i])merge(a[i],b[i]);
	ROF(i,q,1)if(opt[i]==2){
		x=a[val[i]],y=b[val[i]];
		if((x=fa[x])==(y=fa[y]))continue;
		if(siz[x]<siz[y])swap(x,y);
		for(int v:now[y])now[x].push_back(v),fa[v]=x;
		fa[y]=x,siz[x]+=siz[y],dis[i][0]=x,dis[i][1]=y;
	}
	FOR(i,1,n)mp[fa[i]].insert(w[i]);
}
V work(){
	int x,y,p;
	FOR(i,1,q)
		if(opt[i]==1){
			x=fa[val[i]];
			p=*--mp[x].end();
			cout<<p<<'\n';
			w[id[p]]=0;
			mp[x].erase(p);
			mp[x].insert(0);
		}
		else if(dis[i][0]){
			x=dis[i][0],y=dis[i][1];
			FOR(j,1,siz[y])now[x].pop_back();
			siz[x]-=siz[y];
			for(int v:now[y]){
				fa[v]=y,mp[y].insert(w[v]);
				if(mp[x].find(w[v])!=mp[x].end())
					mp[x].erase(w[v]);
			}
			mp[x].insert(0);
		}
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}