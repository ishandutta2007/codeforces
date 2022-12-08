#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

int n, a[sz];
long long b[sz];
pair<long long, int> bb[sz];
long long d[sz];
int c[sz];
int e[sz];
int main()
{
	scanf("%d",&n);
	if(n<3)
	{
		printf("0\n");
		return 0;
	}
	rep(i,0,n)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		if(i>0)
			b[i]+=b[i-1];
		bb[i] = make_pair(b[i],i);
	}
	sort(bb,bb+n);

	int j=0;
	{
		int i=0;
		while(i<n)
		{
			d[j]=bb[i].first;
			while(i<n && bb[i].first==d[j])
			{
				c[j]++;
				e[bb[i].second]=j;
				i++;
			}
			j++;
		}
		c[e[n-1]]--;
	}
	
	long long count=0;
	rep(i,0,n-2)
	{
		c[e[i]]--;
		if(b[i]*3==b[n-1])
		{
		    long long x = 2*b[i];
			int l=0, r=j-1;
			while(l<=r)
			{
				int mid = (l+r)/2;
				if(d[mid]<x)
					l = mid+1;
				else if(x<d[mid])
					r = mid-1;
				else
				{
					count+=c[mid];
					l=r+1;
				}
			}
		}
	}
	printf("%lld\n",count);
}