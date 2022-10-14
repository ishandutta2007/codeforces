#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e3+1,mod=998244353;
P pos[N*N];
int n,m,tot;
vector<int>e[N];
int f[N][N],fa[N],id[N],tag[N];
int a[N][N],nxt[N],l[N],r[N],siz[N],cnt[N];
V check(int&x){x-=mod,x+=x>>31&mod;}
V input(){
	n=getint();
	FOR(i,1,n)FOR(j,1,n)a[i][j]=getint();
}
I find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
V merge(int x,int y){
	if((x=find(x))!=(y=find(y)))
		fa[y]=x,nxt[r[x]]=l[y],r[x]=r[y];
}
I C2(int x){return x*(x-1)/2;}
V init(){
	tot=C2(n),**f=1;
	FOR(i,1,n)FOR(j,i+1,n)pos[a[i][j]]=P(i,j);
	FOR(i,1,n)l[i]=i,r[i]=i,fa[i]=i;
	FOR(i,1,tot)merge(pos[i].first,pos[i].second);
	FOR(i,1,n)tag[nxt[i]]=1;
	FOR(i,1,n)if(!tag[i])id[m=1]=i;
	while(m<n)id[m+1]=nxt[id[m]],m++;
}
V link(int x,int y){
	if((x=find(x))!=(y=find(y)))
		fa[y]=x,r[x]=r[y],siz[x]+=siz[y],cnt[x]+=cnt[y];
	if(++cnt[x]==C2(siz[x]))e[l[x]].push_back(r[x]);
}
V work(){
	FOR(i,1,n)fa[i]=i,l[id[i]]=r[id[i]]=i;
	FOR(i,1,n)siz[i]=1,e[i].push_back(i);
	FOR(i,1,tot)link(pos[i].first,pos[i].second);
	FOR(u,1,n)FOR(i,0,n-1)if(f[u-1][i])for(int v:e[u])
		check(f[v][i+1]+=f[u-1][i]);
	FOR(i,1,n)cout<<f[n][i]<<' ';
		
}
int main(){
	input();
	init();
	work();
	return 0;
}