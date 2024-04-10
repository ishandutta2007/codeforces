#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 70015;
int n, i, j, k, cnt;
ll out, mask;
ll a [N];
ll b [N];
int ord [N];
int bip [N];
bool taken [N];


int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		scanf ("%lld",&a[i]);
	for (i=1; i<=n; i++)
		scanf ("%lld",&b[i]);
	
	for (i=1; i<=n; i++)
		for (j=i+1; j<=n; j++)
			if (a[i]==a[j] && taken[i]==false && taken[j]==false)
				{
				taken[i] = true;
				taken[j] = true;
				out += b[i];
				out += b[j];
				cnt ++;
				}
	
	if (cnt==0)
		return printf ("0\n"), 0;
	
	for (i=1; i<=n; i++)
		ord[i] = i;

	for (i=1; i<=n; i++)
		bip[i] = __builtin_popcount(a[i]);

	sort(ord+1, ord+n+1, [] (int a, int b) {
		return bip[i]>bip[b];
		});
	
	for (k=1; k<=n; k++)
		{
		i = ord[k];
		if (taken[i]==true)
			continue;
		for (j=1; j<=n; j++)
			if (taken[j]==true && (a[j]|a[i])==a[j])
				{
				taken[i] = true;
				out += b[i];
				break;
				}
		}
	
	printf ("%lld\n",out);
	return 0;
	}