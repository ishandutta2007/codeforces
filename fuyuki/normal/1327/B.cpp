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
const int N=2e5+1;
int T,n,tag[N],lk[N];
vector<int>g[N];
V input(){
	FOR(i,1,n)g[i].clear(),tag[i]=lk[i]=0;
	n=getint();
	FOR(i,1,n){
		int x=getint();
		while(x--)
			g[i].push_back(getint());
	}
}
V init(){
	FOR(i,1,n)for(int v:g[i])
		if(!lk[v]){
			lk[v]=1,tag[i]=1;
			break;
		}
}
V work(){
	FOR(i,1,n)if(!tag[i]){
		FOR(j,1,n)if(!lk[j]){
			cout<<"IMPROVE\n";
			cout<<i<<' '<<j<<'\n';
			return;
		}
	}
	cout<<"OPTIMAL\n";
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