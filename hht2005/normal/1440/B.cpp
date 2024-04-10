#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,k;
		long long sum=0;
		scanf("%d%d",&n,&k);
		int c=n-(n/2+n%2-1);
		for(int i=1;i<=n*k;i++)
			scanf("%d",a+i);
		for(int i=n*k-c+1,j=1;j<=k;i-=c,j++)
			sum+=a[i];
		printf("%lld\n",sum);
	}
	return 0;
}