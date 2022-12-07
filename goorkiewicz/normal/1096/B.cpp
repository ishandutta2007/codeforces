#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
ll n, i, L, R, out;
char s [200001];
char l, r;

int main ()
	{
	scanf ("%lld%s",&n,s+1);
	l = s[1];
	r = s[n];
	for (i=1; i<=n; i++)
		{
		if (s[i]==l)
			L++;
		else
			break;
		}
	for (i=n; i>=1; i--)
		{
		if (s[i]==r)
			R++;
		else
			break;
		}
	if (l==r)
		out = (L+1)*(R+1);
	else
		out = L+R+1;
	out%=mod;
	printf ("%lld\n",out);
	return 0;
	}