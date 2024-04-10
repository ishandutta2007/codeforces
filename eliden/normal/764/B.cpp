#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

int main()
{
	int a[sz], n;
	scanf("%d",&n);
	rep(i,1,n+1)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-i+1;i++)
		if((i&1)==1)
		{
			int t = a[i];
			a[i] = a[n-i+1];
			a[n-i+1] = t;
		}
	rep(i,1,n+1)
		printf("%d ",a[i]);
	printf("\n");
}