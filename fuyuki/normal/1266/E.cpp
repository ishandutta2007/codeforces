#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define fs first
#define sc second
#define rnt re int
#define re register
#define mk make_pair
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
const int N=1e6+1;
ll ans;
map<P,int>mp;
int n,m,s,t,u,a[N];
int main(){
	n=getint();FOR(i,1,n)a[i]=getint(),ans+=a[i];
	for(m=getint();m--;){
		s=getint(),t=getint();
		if(u=mp[{s,t}])ans-=max(0,a[u]++),ans+=max(0,a[u]),mp[{s,t}]=0;
		if(u=getint())ans-=max(0,a[u]--),ans+=max(0,a[u]),mp[{s,t}]=u;
		cout<<ans<<'\n';
	}
	return 0;
}