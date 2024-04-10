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
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=1e6+1;
int T,n,m,ans,a[N];
int c[N],s[N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)s[a[i]=getint()]++;
	FOR(i,1,m)c[i]=getint();
}
vector<int>out[N];
V init(){
	int now=0;
	ROF(i,m,1)
		for(int p=1,now=0;s[i]--;ans=max(ans,p)){
			ROF(j,19,0)
				if(p+(1<<j)<=n&&out[p+(1<<j)].size()+1>c[i])
					p+=1<<j;
			if(out[p].size()+1>c[i])p++;
			out[p].push_back(i);
		}
}
V work(){
	cout<<ans<<'\n';
	FOR(i,1,ans){
		cout<<out[i].size()<<' ';
		for(int x:out[i])cout<<x<<' ';
		cout<<'\n';
	}
}
int main(){
	cin.tie(0);
	input();
	init();
	work();
	return 0;
}