#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<ll,int>
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
const int N=2e6+1,mod=998244353;
int n,top;
ll ans,sum;
char st[N];
struct node{
	int x,y;
	ll val(){return 1ll*x*y;}
}sta[N];
V input(){scanf("%d%s",&n,st+1);}
V init(){
	
}
V ins(int x,int y){
	while(top&&sta[top].x<=x)
		sum-=sta[top].val(),y+=sta[top--].y;
	if(y)sta[++top]=(node){x,y};
	sum+=sta[top].val();
}
V work(){
	int now=0;
	FOR(i,1,n){
		if(st[i]=='0'){
			while(now)ins(now--,1);
			ins(0,1);
		}
		else now++,ins(now,0);
		ans+=sum+1ll*now*(now+1)/2;
//		cout<<sum+1ll*now*(now+1)/2<<'\n';
	}
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