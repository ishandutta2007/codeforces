#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;
const int sz = 1e5;
int n, a[sz], m[sz];
int main()
{
	scanf("%d",&n);
	rep(i,0,n)
		scanf("%d",&a[i]);

	int j=-1;
	rep(i,0,n)
	{
		int lo=0, hi=j;
		while(lo<=hi)
		{
			int mid = hi-(hi-lo)/2;
			if(a[m[mid]]<a[i])
				lo = mid+1;
			else
				hi = mid-1;
		}
		m[lo]=i;
		if(lo>j)
			j =lo;
	}
	printf("%d\n",j+1);
}