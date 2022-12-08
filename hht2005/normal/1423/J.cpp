#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int f[2][8];
int main() {
	int T;
	long long m;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&m);
		printf("%lld\n",((m/4+1)%mod*((m/2-m/4+1)%mod))%mod);
	}
	return 0;
}