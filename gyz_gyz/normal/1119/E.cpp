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
int n;ll nw,ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n){ll x;
		scanf("%lld",&x);
		nw+=x;ans=min(nw/3,ans+x/2);
	}
	printf("%lld\n",ans);
}