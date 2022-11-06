#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;ll a[N],ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n/2)ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	printf("%lld\n",ans);
}