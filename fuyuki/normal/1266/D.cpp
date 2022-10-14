//#pragma GCC optimize(3)
#include<set>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re //register
#define LL inline ll
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
LL min(const ll&x,const ll&y){return x<y?x:y;}
const int N=3e5+1;
int n,m,ins[N];
ll d[N],w[N];
int u[N],v[N];
V input(){
	n=getint(),m=getint();rnt x,y,z;
	while(m--)x=getint(),y=getint(),z=getint(),d[x]+=z,d[y]-=z;
}
V init(){}
int sta[N],tp1;
int stb[N],tp2;
V work(){
	FOR(i,1,n){
		if(d[i]>0)sta[++tp1]=i;
		if(d[i]<0)stb[++tp2]=i;
	}
	m=0;
	while(tp1&&tp2){
		rnt x=sta[tp1],y=stb[tp2];
		while(d[x]==0&&tp1)x=sta[--tp1];
		while(d[y]==0&&tp2)y=stb[--tp2];
		if(!tp1||!tp2)break;
		ll z=min(d[x],-d[y]);
		m++,u[m]=x,v[m]=y,w[m]=z;
		d[x]-=z,d[y]+=z;
	}
	cout<<m<<'\n';
	FOR(i,1,m)cout<<u[i]<<' '<<v[i]<<' '<<w[i]<<'\n';
}
int main(){
	input();
	init();
	work();
	return 0;
}