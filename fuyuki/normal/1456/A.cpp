#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,INF=0x3f3f3f3f;
int T,n,p,k,x,y,cnt[N];
char st[N];
V input(){
	scanf("%d%d%d",&n,&p,&k);
	scanf("%s%d%d",st+1,&x,&y);
	FOR(i,0,k-1)cnt[i]=0;
	int ans=INF;
	ROF(i,n,p){
		cnt[i%k]+=st[i]=='0';
		ans=min(ans,(i-p)*y+cnt[i%k]*x);
	}
	cout<<ans<<'\n';
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}