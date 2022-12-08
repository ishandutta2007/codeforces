#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,mod=998244353;
int a[maxn],p[maxn];
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m) {
	int ans1=1,ans2=1;
	for(int i=1;i<=m;i++) {
		ans1=1ll*ans1*i%mod;
		ans2=1ll*ans2*(n-i+1)%mod;
	}
	return 1ll*ans2*qpow(ans1,mod-2)%mod;
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	k--;
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		p[a[i]]=i;
	}
	for(int i=1;i<n;i++)
		if(p[a[i]+1]>p[a[i+1]+1])
			k--;
	if(k<0)puts("0");
	else printf("%d\n",C(n+k,k)); 
	return 0;
}