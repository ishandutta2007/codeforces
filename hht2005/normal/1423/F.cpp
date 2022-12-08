#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int main() {
	int n,k,a,b,sum=0;
	long long Sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) {
		scanf("%d%d",&a,&b);
		Sum+=b;
		sum=(sum+1ll*a*b)%n;
	}
	if(Sum<n)puts("1");
	else if(Sum>n)puts("-1");
	else {
		if(sum==(1ll*n*(n+1)/2%n))puts("1");
		else puts("-1");
	}
	return 0;
}