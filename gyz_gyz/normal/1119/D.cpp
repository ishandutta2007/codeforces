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
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000001ll
using namespace std;
typedef long long ll;
int n,q;ll a[N],b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n-1)a[i]=a[i+1]-a[i];
	a[n]=Inf;sort(a+1,a+n+1);
	rep(i,1,n)b[i]=b[i-1]+a[i];
	scanf("%d",&q);
	while(q--){ll x,y;
		scanf("%lld%lld",&y,&x);x-=y-1;
		int l=0,r=n,m=(l+r+1)/2;
		for(;l<r;m=(l+r+1)/2)if(a[m]>x)r=m-1;else l=m;
		printf("%lld ",(n-m)*x+b[m]);
	}
}