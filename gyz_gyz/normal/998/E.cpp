#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
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
#define N 2000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n;ll c[N],ans;
ll rw(ll x){if(x&1)return 1;return mo-1;}
ll qk(ll x,ll y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){
	scanf("%d",&n);c[0]=1;
	rep(i,1,n)c[i]=c[i-1]*(n-i+1)%mo*qk(i,mo-2)%mo;
	rep(i,1,n)ans=(ans+2*c[i]*qk(3,i+1ll*(n-i)*n)%mo*rw(i))%mo;
	rep(i,0,n-1)ans=(ans+3*c[i]*rw(i)%mo*(qk(mo+1-qk(3,i),n)+mo-qk(mo-qk(3,i),n)))%mo;
	printf("%I64d\n",ans);
}