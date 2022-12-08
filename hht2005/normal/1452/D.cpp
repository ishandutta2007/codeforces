#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,inv2=499122177;
int main() {
	int n,O=0,E=1,P=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		if(i&1)O=(O+E)%mod;
		else E=(E+O)%mod;
		P=1ll*P*inv2%mod;
	}
	if(n&1)printf("%lld\n",1ll*E*P%mod);
	else printf("%lld\n",1ll*O*P%mod);
	return 0;
}