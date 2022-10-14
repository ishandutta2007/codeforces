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
V cmin(int&x,int y){if(y-x>>31)x=y;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
I gcd(int x,int y){return!y?x:gcd(y,x);}
const int N=1e6+1,mod=998244353;
ll ans;
int n,m,k,tot;
int a[N],b[N],fa[N];
struct node{
	int x,y,w;
	I operator<(const node&u)const{
		return w>u.w;
	}
}e[N];
V input(){
	n=getint(),m=getint(),tot=n+m;
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,m)b[i]=getint();
	FOR(i,1,n)
		for(int cnt=getint(),x;cnt--;)
			x=getint(),e[++k]=(node){x,i+m,a[i]+b[x]};
}
V init(){
	FOR(i,1,tot)fa[i]=i;
	sort(e+1,e+1+k);
}
I find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
I merge(int x,int y){
	if((x=find(x))==(y=find(y)))return 0;
	return fa[x]=y,1;
}
V work(){
	FOR(i,1,k)
		if(!merge(e[i].x,e[i].y))
			ans+=e[i].w;
	cout<<ans;
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