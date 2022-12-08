#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long a[maxn],sum,L=1,R=1e12;
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		sum+=a[i];
	}
	while(L<=R) {
		long long mid=(L+R)>>1;
		if((mid+mid+n-1)*n/2<=sum)L=mid+1;
		else R=mid-1;
	}
	L--;
	int I=sum-(L+L+n-1)*n/2;
	for(int i=1;i<=I;i++)
		printf("%lld ",L+i);
	for(int i=I+1;i<=n;i++)
		printf("%lld ",L+i-1);
	return 0;
}