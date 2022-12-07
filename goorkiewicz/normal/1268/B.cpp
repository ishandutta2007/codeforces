#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i;
ll a, cnt1, cnt2;

int main ()
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++)
		{
		scanf ("%lld", &a);
		cnt1 += a/2;
		cnt2 += a/2;
		if (i%2==0) cnt1 += a%2;
		if (i%2==1) cnt2 += a%2;
		}
	printf ("%lld\n", min(cnt1, cnt2));
	return 0;
	}