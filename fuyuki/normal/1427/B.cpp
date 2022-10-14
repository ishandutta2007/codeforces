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
//int T,n,sum,a[N];
int T,n,k,tot,ans,w[N];
char a[N];
V input(){
	scanf("%d%d%s",&n,&k,a+1),a[n+1]='L',tot=0;
	int now=0,flag=0;
	FOR(i,1,n)if(a[i]=='W'){
		if(!flag)flag=1,now=0;
		else if(now)
			w[++tot]=now,now=0;
	}
	else if(flag)now++;
	ans=0;
	FOR(i,1,n)if(a[i]=='W')
		ans++,ans+=a[i]==a[i-1];
}
V init(){
	sort(w+1,w+1+tot);
	FOR(i,1,tot)
		if(w[i]>k)ans+=k<<1,k=0;
		else ans+=w[i]<<1|1,k-=w[i];
	int flag=0;
	FOR(i,1,n)if(a[i]=='W')flag=1;
	if(!flag)
		return void(cout<<max(0,k*2-1)<<'\n');
	ans+=k<<1;
	ans=min(ans,n*2-1);
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