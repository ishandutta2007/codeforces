#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;ll tot,l,r,m,e,t,nw,vs,a[N];char s[N];
bool ck(ll x){
	bool fl=0;ll e=0,nw=0;
	rep(i,1,n){
		if(s[i]=='W'||(s[i]=='G'&&nw+a[i]<x))e+=a[i];
		else if(s[i]=='L'||(s[i]=='G'&&nw>x)){
			if(s[i]=='G')fl=1;e-=a[i];
		}else e+=(x-nw)*2-a[i],fl=1;
		if(e<0){
			if(fl)return 0;e=0;
		}nw+=a[i];
	}return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld",&a[i]);a[i]*=2;tot+=a[i];
	}
	scanf("%s",s+1);
	l=0;r=tot;m=(l+r)/2;vs=5;
	for(;r>l;m=(l+r)/2)if(ck(m))r=m;else l=m+1;
	rep(i,1,n){
		if(s[i]=='W')e+=a[i],t+=3*a[i],vs=3;
		else if(s[i]=='L'||nw>m){
			e-=a[i];t+=a[i];
			if(e<0)t-=vs*e,e=0;
		}else if(nw+a[i]<m)e+=a[i],t+=5*a[i];
		else e+=(m-nw)*2-a[i],t+=(m-nw)*4+a[i];nw+=a[i];
	}
	printf("%lld\n",(t-e)/2);
}