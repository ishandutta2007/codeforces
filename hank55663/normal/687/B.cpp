#include<bits/stdc++.h>
using namespace std;
main(){
	long long int n,k;
	scanf("%I64d %I64d",&n,&k);
	long long int now;
	scanf("%I64d",&now);
	for(int i=1;i<n;i++){
		long long int a;
		scanf("%I64d",&a);
		now=a*now/__gcd(a,now);
		now%=k;
	}
	if(now%k==0)
	printf("Yes\n");
	else
	printf("No\n");
}