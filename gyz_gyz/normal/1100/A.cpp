#include<cstdio>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N];
int main(){int n,k,ans=0,tot=0;
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);tot+=a[i];
	}
	rep(i,1,k){int x=tot;
		rep(j,0,(n-i)/k)x-=a[j*k+i];
		ans=max(ans,abs(x));
	}
	printf("%d\n",ans);
}