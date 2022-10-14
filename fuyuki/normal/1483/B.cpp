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
const int N=2e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
set<int>mp;
int T,n,m,a[N],pre[N],nxt[N];
I gcd(int x,int y){return!y?x:gcd(y,x%y);}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){
	FOR(i,1,n-1)nxt[i]=i+1;
	FOR(i,2,n)pre[i]=i-1;
	pre[1]=n,nxt[n]=1;
}
V del(int x){
	x[pre][nxt]=x[nxt],x[nxt][pre]=x[pre];
}
V ins(int x){
//	if(gcd(a[x],a[pre[x]])==1)mp.insert(x);
//	if(gcd(a[nxt[x]],a[x])==1)mp.insert(nxt[x]);
}
V work(){
	vector<int>ans;
	FOR(i,1,n)
		if(gcd(a[i],a[pre[i]])==1)
			mp.insert(i);
	int p=1;
	set<int>::iterator it;
	while(!mp.empty()){
		it=mp.upper_bound(p);
		if(it==mp.end())
			p=0,it=mp.upper_bound(p);
		p=*it,ans.push_back(p);
		if(ans.size()==n)break;
		mp.erase(p),del(p);
		if(gcd(a[nxt[p]],a[p])==1)
			mp.erase(nxt[p]);
		if(gcd(a[pre[p]],a[nxt[p]])==1)
			mp.insert(nxt[p]);
		p=nxt[p];
	}
	cout<<ans.size()<<' ';
	for(int v:ans)cout<<v<<' ';
	cout<<'\n',mp.clear();
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}