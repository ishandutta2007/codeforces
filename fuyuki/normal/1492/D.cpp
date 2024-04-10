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
const int N=3e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int a,b,k;
char st[N];
V input(){
	cin>>a>>b>>k;
	if(b==1||a==0){
		if(k>0)return void(cout<<"No");
		cout<<"Yes\n";
		FOR(i,1,b)cout<<1;
		FOR(i,1,a)cout<<0;
		cout<<'\n';
		FOR(i,1,b)cout<<1;
		FOR(i,1,a)cout<<0;
		cout<<'\n';
		return;
	}
	if(k>a+b-2)
		return void(cout<<"No");
	cout<<"Yes\n";
	int n=0;
	FOR(i,1,b)st[++n]='1';
	FOR(i,1,a)st[++n]='0';
	cout<<st+1<<'\n';
	while(st[n-k]=='0')n--;
	swap(st[n],st[n-k]);
	cout<<st+1;
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}