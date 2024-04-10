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
int n,tot;ll a[N];
void sol(ll x){
	a[++tot]=(2+n-x)*n/x/2;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		if(i*i==n)sol(i);
		if(i*i>=n)break;
		if(!(n%i))sol(i),sol(n/i);
	}
	sort(a+1,a+tot+1);
	rep(i,1,tot)printf("%lld ",a[i]);
}