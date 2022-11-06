#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;ll a[N],b[N];
int main(){
	scanf("%d",&n);n/=2;
	rep(i,1,n)scanf("%lld",&b[i]);a[n]=b[n]/2;
	dep(i,n-1,1)a[i]=min(a[i+1],b[i]-b[i+1]+a[i+1]);
	rep(i,1,n)printf("%lld ",a[i]);
	dep(i,n,1)printf("%lld ",b[i]-a[i]);
}