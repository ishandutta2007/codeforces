#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 300050
typedef long long ll;
ll n,K;
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld",&n,&K);
		ll ans=0;
		while(n) {
			if(n%K==0) {
				n/=K; ans++; continue;
			}
			ans+=n%K, n-=n%K;
		}
		printf("%lld\n",ans);
	}
}