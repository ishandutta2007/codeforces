#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 300000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;ll a[N];
bool ck(ll x){
	if(x<=0)return 0;
	ll y=sqrt(x);
	return y*y==x;
}
void dfs(int x,int t){
	if(x==1){
		printf("Yes\n");a[1]=1ll*t*t;
		rep(i,1,n)printf("%lld ",a[i]);exit(0);
	}
	dep(i,t-1,1){
		if(1ll*i*i<=a[x-1])break;
		ll r=1ll*i*i-a[x-1];
		if(ck(r)){
			a[x]=1ll*t*t-1ll*i*i;
			dfs(x-2,sqrt(r));
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n/2)scanf("%lld",&a[i*2]);
	rep(i,1,100000)if(ck(1ll*i*i-a[n]))
		dfs(n-1,sqrt(1ll*i*i-a[n]));
	printf("No\n");
}