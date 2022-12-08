#include<bits/stdc++.h>
using namespace std;
int mu[70],p[70],fl[70],tot;
__int128 qpow(long long a,int b) {
	__int128 ans=1;
	for(int i=1;i<=b;i++)
		ans*=a;
	return ans;
}
int main() {
	mu[1]=1;
	for(int i=2;i<=60;i++) {
		if(!fl[i])mu[p[++tot]=i]=-1;
		for(int j=1;j<=tot&&p[j]*i<=60;j++) {
			fl[p[j]*i]=1;
			if(i%p[j]==0)break;
			mu[p[j]*i]=-mu[i];
		}
	}
	int T;
	long long n; 
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&n);
		long long ans=0;
		for(int i=1;i<=60;i++) {
			long long t=pow(n,1.0/i);
			while(qpow(t,i)>n)t--;
			while(qpow(t+1,i)<=n)t++;
			ans=ans+(t-1)*mu[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}