#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int l[maxn],r[maxn],a[maxn],n,k;
long long f[maxn];
int main() {
	scanf("%d%d",&n,&k);
	long long ans=0,cnt=0;
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",l+i,r+i,a+i);
		ans+=a[i];
	}
	for(int i=n;i>=1;i--) {
		long long nd=a[i]+(r[i]==l[i+1]?f[i+1]:0);
		if(1ll*(r[i]-l[i]+1)*k<nd)return puts("-1"),0;
		f[i]=max(0ll,nd-1ll*(r[i]-l[i])*k);
	}
	for(int i=1;i<=n;i++) {
		if(cnt<f[i])ans+=cnt,cnt=k;
		cnt=(((cnt-a[i])%k)+k)%k; 
	}
	printf("%lld\n",ans);
}