#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve ()
	{
	ll n;
	scanf ("%lld", &n);
	if (n<=14)
		return false;
	n %= 14;
	if (n > 0 && n <= 6)
		return true;
	return false;
	}

int main ()
	{
	int q;
	scanf ("%d", &q);
	while (q--)
		printf ("%s\n", solve() ? "YES" : "NO");
	return 0;
	}