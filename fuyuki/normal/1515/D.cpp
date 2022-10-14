#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
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
int T,n,l,r,ans,a[N];
vector<int>b,c;
V input(){
	n=getint(),l=getint(),r=getint(),ans=0;
	FOR(i,1,n)a[i]=getint();
}
V init(){
	sort(a+1,a+1+l),sort(a+n+1-r,a+1+n);
	b.clear(),c.clear();
	int p=1,q=l+1;
	while(p<=l&&q<=n){
		if(a[p]==a[q])p++,q++;
		else if(a[p]<a[q])b.push_back(a[p++]);
		else c.push_back(a[q++]);
	}
	while(p<=l)b.push_back(a[p++]);
	while(q<=n)c.push_back(a[q++]);
	if(b.size()>c.size())swap(b,c);
	int x=0,cx=0,cy=0,y=0,last=0,v;
	for(int v:b){
		x++;
		if(v==last)last=0,x-=2,cx+=2;
		else last=v;
	}
	last=0;
	for(int v:c){
		y++;
		if(v==last)last=0,y-=2,cy+=2;
		else last=v;
	}
	v=cy+y-cx-x,ans+=cy+y-min(v,cy)/2;
	cout<<ans<<'\n';
}
V work(){
	
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