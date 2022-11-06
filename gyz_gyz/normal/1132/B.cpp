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
#define N 300010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,a[N];ll ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);ans+=a[i];
	}
	sort(a+1,a+n+1);scanf("%d",&m);
	rep(i,1,m){int x;
		scanf("%d",&x);
		printf("%lld\n",ans-a[n-x+1]);
	}
}