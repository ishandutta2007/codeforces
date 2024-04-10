#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 300050
typedef long long ll;
int n,s[N][2],a[N];
ll ans,S[N];
int main() {
	scanf("%d",&n);
	int i,j;
	ll x;
	s[0][0]=1;
	for(i=1;i<=n;i++) {
		scanf("%lld",&x);
		for(;x;x-=x&(-x))a[i]++;
		int mx=a[i],sum=a[i];
		for(j=i-1;j>=1&&j>=i-70;j--) {
			mx=max(mx,a[j]);
			sum+=a[j];
			ans+=(!(sum&1)&&mx<=sum-mx);
		}
		S[i]=S[i-1]+a[i];
		if(i>71) ans+=s[i-72][S[i]&1];
		s[i][0]=s[i-1][0],s[i][1]=s[i-1][1];
		s[i][S[i]&1]++;
	}
	printf("%lld\n",ans);
}