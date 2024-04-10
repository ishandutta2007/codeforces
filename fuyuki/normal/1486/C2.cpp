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
ll ans;
int T,n,a[N],b[N];
I ask(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	cin>>l;
	return l;
}
V input(){
	cin>>n;
	int p,l,r,mid;
	p=ask(1,n);
	if(p==1||ask(1,p)!=p){
		l=p+1,r=n;
		while(mid=l+r>>1,l^r)
			if(ask(p,mid)==p)r=mid;
			else l=mid+1;
		cout<<"! "<<mid<<endl;
	}
	else{
		l=1,r=p-1;
		while(mid=l+r>>1,l^r)
			if(ask(mid+1,p)==p)l=mid+1;
			else r=mid;
		cout<<"! "<<mid<<endl;
	}
}
V init(){
	
}
V work(){
	
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