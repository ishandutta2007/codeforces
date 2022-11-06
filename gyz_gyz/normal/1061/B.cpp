#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;ll h,ans,a[N];
int main(){
	scanf("%d%lld",&n,&h);
	rep(i,1,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);h=a[n];
	dep(i,n-1,0){
		ans+=a[i+1]-h+min(h-1,a[i]);
		h=min(h-1,a[i]);
	}
	printf("%lld\n",ans);
}