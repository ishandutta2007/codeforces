#include<bits/stdc++.h>
using namespace std;
const int pps=1e6;
long long f[8],dp[pps+10],v[pps+10],w[pps+10],tot;
int main() {
	int k,q,n;
	scanf("%d",&k);
	for(int i=1;i<=6;i++)
		scanf("%lld",f+i);
	for(int i=1,P=3;i<=6;i++,P*=10) {
		int kk=3*(k-1),p=1;
		while(p<kk) {
			w[++tot]=1ll*p*f[i];
			v[tot]=1ll*P*p;
			kk-=p;
			p<<=1;
		}
		w[++tot]=1ll*kk*f[i];
		v[tot]=1ll*P*kk;
	}
	for(int i=1;i<=pps;i++) {
		int t=i,p=1;
		while(t) {
			int x=t%10;
			if(x%3==0)dp[i]+=x/3*f[p];
			p++;
			t/=10;
		}
	}
	for(int i=1;i<=tot;i++)
		for(int j=pps;j>=v[i];j--)
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}