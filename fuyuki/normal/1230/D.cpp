#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
LL getint(){
	static const int flag[2]={1,-1};
	re ll _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
//V getstr(char*out,int&len){
//	re char ch=gc;len=0;
//	while(ch<'0'||ch>'9')ch=gc;
//	while(ch>='0'&&ch<='9')out[++len]=ch,ch=gc;
//}
//I lowbit(const int&x){return x&-x;}
//I max(const int&x,const int&y){return x>y?x:y;}
//I min(const int&x,const int&y){return x<y?x:y;}
const int N=7e3+1;
int n,m,tot,b[N],d[N],h[N];
ll a[N],ans;
//struct edge{int t,n;}e[N*N];
//V add_edge(rnt x,rnt y){e[++tot]=(edge){y,h[x]},h[x]=tot,d[y]++;}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,n)b[i]=getint(),ans+=b[i];
}
V init(){
	
	FOR(i,1,n)FOR(j,1,n)if(i!=j&&!(a[i]&~a[j]))
		d[i]++;//,cout<<j<<' '<<i<<'\n';
}
int sta[N],top;
V work(){
	FOR(i,1,n)if(d[i]==0)sta[++top]=i;
	while(top){
		rnt u=sta[top--];
		ans-=b[u];
		FOR(i,1,n)if(i!=u&&!(a[i]&~a[u]))
			if(!--d[i])sta[++top]=i;
//		REP(u)if(!--d[v])sta[++top]=v;
	}
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
//	cout<<sizeof(e)/1024/1024;
	input();
	init();
	work();
	return 0;
}