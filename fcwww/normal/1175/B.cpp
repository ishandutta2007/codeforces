#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 100050
typedef long long ll;
int n;
ll S[N],LIM,sum[N];
int tp;
inline void gun() {
	puts("OVERFLOW!!!"); exit(0);
}
int main() {
	scanf("%d",&n);
	int i;
	LIM=(1ll<<32)-1;
	char opt[10];
	sum[0]=1;
	ll ans=0;
	for(i=1;i<=n;i++) {
		scanf("%s",opt);
		if(opt[0]=='a') {
			ans+=sum[tp];
			if(ans>LIM) gun();
		}else if(opt[0]=='e') tp--;
		else {
			ll x;
			scanf("%lld",&x);
			S[++tp]=x;
			sum[tp]=sum[tp-1]*x;
			sum[tp]=min(sum[tp],1ll<<50);
		}
	}
	printf("%lld\n",ans);
}