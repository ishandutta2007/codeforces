#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 400000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int T;ll ans,n,s,ls,a[200];
ll qk(ll r,ll x,int y){
	for(;y;y>>=1){
		if(y&1)r=r/x;x=x*x;
	}return r;
}
ll cal(int x){
	ll p=(ll)(pow(n,(1./x))+eps);
	if(!qk(n,p,x))return p-2;return p-1;
}
int main(){
	rep(i,2,100){a[i]=-1;
		rep(j,1,i-1)if(!(i%j))a[i]-=a[j];
	}
	for(scanf("%d",&T);T;T--){
		scanf("%I64d",&n);
		ans=n-1;
		rep(i,2,100){
			s=cal(i);if(!s)break;
			ans+=a[i]*s;
		}
		printf("%I64d\n",ans);
	}
}