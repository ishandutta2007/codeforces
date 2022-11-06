#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
ll sx,sy,tx,ty,dx[N],dy[N];int n;char s[N];
int main(){
	scanf("%lld%lld%lld%lld%d%s",&sx,&sy,&tx,&ty,&n,s+1);
	rep(i,1,n){
		dx[i]=dx[i-1];dy[i]=dy[i-1];
		if(s[i]=='U')++dy[i];
		if(s[i]=='D')--dy[i];
		if(s[i]=='L')--dx[i];
		if(s[i]=='R')++dx[i];
	}
	ll l=0,r=1e15,m=(l+r)/2;
	for(;l<r;m=(l+r)/2)
		if(abs(sx+m/n*dx[n]+dx[m%n]-tx)+
		abs(sy+m/n*dy[n]+dy[m%n]-ty)<=m)r=m;else l=m+1;
	printf("%lld\n",m==1e15?-1:m);
}