#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define VI vector<int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1;
ll ans;VI a[3];int T,n[3];
ll pw(int x){return 1ll*x*x;}
ll calc(int x,int y,int z){return pw(x-y)+pw(y-z)+pw(x-z);}
V solve(const VI&a,const VI&b,const VI&c){
	int p=0,q=0,y,z;
	for(int x:a){
		while(p<b.size()&&b[p]<x)p++;
		if(p==b.size())return;y=b[p];
		while(q<c.size()&&2*c[q]<x+y)q++;
		if(q<c.size())z=c[q],ans=min(ans,calc(x,y,z));
		if(q)z=c[q-1],ans=min(ans,calc(x,y,z));
	}
}
int main(){
	for(scanf("%d",&T);ans=1ll<<62,T--;cout<<ans<<'\n'){
		FOR(i,0,2)a[i].resize(n[i]=getint());
		FOR(i,0,2)FOR(j,0,n[i]-1)a[i][j]=getint();
		FOR(i,0,2)sort(a[i].begin(),a[i].end());
		FOR(i,0,2)FOR(j,0,2)FOR(k,0,2)if(i!=j&&i!=k&&j!=k)
			solve(a[i],a[j],a[k]);
	}
	return 0;
}