#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int n, i;
ll out;
ll t [N];
map <int,ll> cnt;

int main ()
	{
	scanf ("%d", &n);

	for (i=1; i<=n; i++)
		{
		scanf ("%lld", &t[i]);
		cnt[t[i] - i] += t[i];
		}
	
	for (pair <int, ll> p : cnt)
		out = max(out, p.second);

	printf ("%lld\n", out);
	return 0;
	}