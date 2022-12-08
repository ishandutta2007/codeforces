#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int tot;
long long s[N],a[N];
void calc(long long x) {
	for(long long i=2;i*i<=x;i++) {
		if(x%i==0)s[++tot]=i;
		while(x%i==0)x/=i;
	}
	if(x>1)s[++tot]=x;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=30;i++) {
		int I=1ll*rand()*rand()%n+1;
		calc(a[I]);
		calc(a[I]+1);
		calc(a[I]-1);
	}
	sort(s+1,s+tot+1);
	tot=unique(s+1,s+tot+1)-s-1;
	ll ans=1e18;
	for(int i=1;i<=tot;i++) {
		ll sum=0;
		for(int j=1;j<=n;j++) {
			long long w=a[j]<s[i]?1e18:a[j]%s[i];
			sum+=min(w,s[i]-a[j]%s[i]);
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}