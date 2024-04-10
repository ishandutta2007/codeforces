#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 300050
typedef long long ll;
int n,K,a[N];
ll s[N];
int main() {
	scanf("%d%d",&n,&K);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	sort(s+1,s+n);
	ll ans=0;
	for(i=1;i<K;i++) ans-=s[i];
	ans+=K*s[n];
	//for(i=1;i<=n;i++) printf("%lld\n",s[i]);
	printf("%lld\n",ans);
}