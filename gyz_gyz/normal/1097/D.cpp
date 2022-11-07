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
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
ll n,ans,a[N],f[N],s[N],r[N];int t[N],k,tot;
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){
	scanf("%lld%d",&n,&k);ans=1;
	rep(i,2,n){
		if(n/i<i)break;
		if(!(n%i)){
			a[++tot]=i;
			while(!(n%i))n/=i,++t[tot];
		}
	}
	if(n>1)a[++tot]=n,t[tot]=1;
	rep(i,1,tot){int m=t[i];
		rep(j,0,m)r[j]=qk(j+1,mo-2);
		rep(j,0,m)s[j]=r[m];
		rep(o,1,k){
			rep(j,0,m)f[j]=s[j];s[m]=f[m]*r[m]%mo;
			dep(j,m-1,0)s[j]=(s[j+1]+f[j]*r[j])%mo;
		}ll x=0,y=1;
		rep(j,0,m){
			add(x,f[j]*y%mo);
			y=y*a[i]%mo;
		}
		ans=ans*x%mo;
	}
	printf("%lld\n",ans);
}