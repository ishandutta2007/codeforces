#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
int i, j;
ll t [1000001];
ll sum, v;

int main ()
	{
	scanf ("%lld",&n);
	for (i=0; i<n; i++)
		{
		scanf ("%lld",&t[i]);
		sum+=t[i];
		}
	if (n==1)
		{
		if (t[0]%2==1)
			return printf ("sjfnb\n"), 0;
		if (t[0]%2==0)
			return printf ("cslnb\n"), 0;
		}
	
	sort(t, t+n);
	
	if (t[0]==0 && t[1]==0)
		return printf ("cslnb\n"), 0;
	
	bool ok = true;
	for (i=0; i<n; i++)
		{
		if (t[i]==t[i+1])
			{
			if (ok==false)
				return printf ("cslnb\n"), 0;
			if (i>0 && t[i]==t[i-1])
				return printf ("cslnb\n"), 0;
			if (i>0 && t[i]==t[i-1]+1)
				return printf ("cslnb\n"), 0;
			ok = false;
			}
		}
	v = (n*(n-1))/2;
	sum -= v;
	if (sum%2==1)
		return printf ("sjfnb\n"), 0;
	if (sum%2==0)
		return printf ("cslnb\n"), 0;
	return 0;
	}