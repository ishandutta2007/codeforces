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
const int N=5e5+1;
const ll INF=1ll<<62;
int n,m,a[N],b[N],p[N],pre[N],tag[N],ok[N];
ll dp[N],sum,t[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,n)p[i]=getint(),sum+=p[i];
	m=getint();
	FOR(i,1,m)b[i]=getint(),pre[b[i]]=b[i-1],tag[b[i]]=1;
}
I lowbit(int x){return x&-x;}
V add(int x,ll y){
	t[0]+=y;
	while(x)t[x]+=y,x^=lowbit(x);
}
ll ask(int x){
	if(x==0)return t[0];
	ll out=0;
	while(x<=n)out+=t[x],x+=lowbit(x);
	return out;
}
V init(){
	ok[0]=1;
}
V work(){
	ll x,y;
	FOR(i,1,n){
		if(i==5){
			i=5;
		}
		x=ask(pre[a[i]]);
		if(p[i]>0)add(a[i]-1,p[i]);
		else add(n,p[i]);
		if(tag[a[i]]&&ok[pre[a[i]]]){
			y=ask(a[i]);
			if(!ok[a[i]]||x<y)
				ok[a[i]]=1,x-=y,add(a[i],x),add(a[i]-1,-x);
		}
	}
	if(!ok[b[m]])
		cout<<"NO\n";
	else cout<<"YES\n"<<ask(b[m]);
}
int main(){
	input();
	init();
	work();
	return 0;
}