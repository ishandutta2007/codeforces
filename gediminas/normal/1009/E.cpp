#include<bits/stdc++.h>

using namespace std;


int main(){
	int n;
	scanf("%d", &n);
	long long b[n];
	for(int i =0;i<n;i++)
		scanf("%I64d", b + i);
	
	const long long mod = 998244353;
	long long ats = 0, daug = 1, dv = 1;
	for(int i = n-1;i>=0;i--){
		ats+=(b[i]*daug)%mod;
		ats%=mod;
		daug = daug * 2 + dv;
		while(daug > mod)
			daug -= mod;
		dv *= 2;
		while(dv > mod)
			dv -= mod;
	}
	printf("%I64d", ats);
}