#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <set>
using namespace std;
typedef long long ll;
int n;
int main() {
	scanf("%d",&n);
	int i;
	ll s=0,ans=0,x;
	for(i=1;i<=n;i++) {
		scanf("%lld",&x);
		ll t=min(x/2,s);
		ans+=t;
		x-=(t<<1);
		s-=t;
		ans+=x/3;
		s+=x%3;
	}
	printf("%lld\n",ans);
}