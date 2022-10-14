#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
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
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=2e5+1,INF=0x3f3f3f3f;
int T,n,m,ans=INF;
int p[N],c[N],tag[N],tmp[N];
V input(){
	n=getint();
	FOR(i,1,n)p[i]=getint();
	FOR(i,1,n)c[i]=getint();
}
V init(){
	FOR(i,1,n)tag[i]=0;ans=INF;
}
V test(){
	FOR(i,1,m){
		if(i>ans)return;
		if(m%i==0)
			FOR(j,1,i){
				int x=j,flag=tmp[j];
				for(;x<=m;x+=i)if(tmp[x]!=flag)break;
			if(x>m)return void(ans=i);
		}
	}
}
V work(){
	FOR(i,1,n)if(!tag[i]){
		int x=i;
		while(!tag[x])
			tag[x]=1,tmp[++m]=c[x],x=p[x];
		test(),m=0;
	}
	cout<<ans<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}