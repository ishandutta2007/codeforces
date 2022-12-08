#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
const int sz=1e6;
int n, a[sz];
int main()
{
	scanf("%d",&n);
	rep(i,0,n)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int lo=0, hi=n/2;
	while(lo<hi)
	{
		int mid = hi-(hi-lo)/2;
		bool ok = true;
		rep(i,0,mid)
			if(a[i]*2>a[n-mid+i])
				ok=false;
		if(ok)
			lo = mid;
		else
			hi = mid-1;
	}
	printf("%d\n",n-lo);
}