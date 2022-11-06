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
#define M 10000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){int n,a1=0,b1=0,a2,b2,ans=1;
	scanf("%d",&n);
	while(n--){a2=a1;b2=b1;
		scanf("%d%d",&a1,&b1);
		ans+=max(0,min(a1,b1)-(a2==b2?a2+1:max(a2,b2))+1);
	}
	printf("%d\n",ans);
}