#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I min(const int&x,const int&y){return x<y?x:y;}
I max(const int&x,const int&y){return x>y?x:y;}
const int N=2e6+1;
int n,m,a,b,s1,s2,s3,tot;
int siz[N],h[N],tag[N],X[N],Y[N],fa[N];
ll ans;
struct edge{int t,n;}e[N<<1];
V add_edge(rnt x,rnt y){
//	cout<<x<<' '<<y<<'\n';
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
}
V input(){
	n=getint(),m=getint();
	a=getint(),b=getint();
	if(a>b)swap(a,b);
	FOR(i,1,m){
		X[i]=getint(),Y[i]=getint();
		if(X[i]>Y[i])swap(X[i],Y[i]);
	}
}
I find(rnt x){return fa[x]==x?x:fa[x]=find(fa[x]);}
V merge(rnt x,rnt y){
	x=find(x),y=find(y);
	if(x==y)return;
	fa[x]=y,siz[y]+=siz[x];
//	cout<<x<<' '<<y<<'\n';
}
V init(){
	FOR(i,1,n)fa[i]=i,siz[i]=1;
	FOR(i,1,m)if(X[i]!=a&&Y[i]!=b&&X[i]!=b&&Y[i]!=a)
		merge(X[i],Y[i]);
	FOR(i,1,m)
		X[i]=find(X[i]),Y[i]=find(Y[i]);
	FOR(i,1,m)if(X[i]!=Y[i])
		add_edge(X[i],Y[i]);
}
V work(){
	tag[a]=tag[b]=8;
	REP(a)
		tag[v]|=1;
	REP(b)
		tag[v]|=2;
	REP(a)if(tag[v]==1)
		s1+=siz[v],tag[v]=8;
	REP(b)if(tag[v]==2)
		s2+=siz[v],tag[v]=8;
	ans=1ll*s1*s2;
//	REP(a)if(tag[v]==3)
//		ans+=1ll*s3*siz[v],s3+=siz[v],tag[v]=8;
	cout<<ans<<'\n';
}
V clean(){
	FOR(i,1,n)tag[i]=h[i]=siz[i]=0;
	tot=s1=s2=s3=ans=0;
}
int main(){
	int T;T=getint();
	while(T--){
		input();
		init();
		work();
		clean();
	}
	return 0;
}