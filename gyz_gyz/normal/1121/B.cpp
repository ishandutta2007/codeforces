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
#define N 250010
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,ans,a[N],p[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		rep(j,1,i-1)++p[a[i]+a[j]];
	}
	rep(i,1,200000)ans=max(ans,p[i]);
	printf("%d\n",ans);
}