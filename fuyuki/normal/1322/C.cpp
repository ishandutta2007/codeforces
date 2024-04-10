#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define uint unsigned long long 
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
ll getint(){
	static const int flag[2]={1,-1};
	ll _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=5e5+2,INF=0x7fffffff;
int T,n,m,tot;
ll ans,sum,a[N];
uint pw[N],tag[N];
map<uint,ll>mp;
vector<int>e[N];
V input(){
	n=getint(),m=getint(),mp.clear();
	int x,y;
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,m){
		x=getint(),y=getint();
		e[x].push_back(y);
	}
}
ll gcd(ll x,ll y){return!y?x:gcd(y,x%y);}
I o(){
	static mt19937 seed(time(0));
	return abs((int)seed());
}
V init(){
	pw[0]=1,ans=0;
	FOR(i,1,n)pw[i]=pw[i-1]+o();
	FOR(i,1,n)for(int v:e[i])tag[v]^=pw[i];
	FOR(i,1,n)if(tag[i])mp[tag[i]]+=a[i];
	FOR(i,1,n)if(tag[i])ans=gcd(mp[tag[i]],ans);
}
V work(){cout<<ans<<'\n';}
V clean(){
	FOR(i,1,n)e[i].clear(),tag[i]=0;
	tot=0;
}
int main(){
	for(T=getint();T--;){
		input();
		init();
		work();
		clean();
	}
	return 0;
}