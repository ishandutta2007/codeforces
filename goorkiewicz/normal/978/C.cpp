#include <bits/stdc++.h>
using namespace std;

int n, q, i;
long long x;
long long t [200002];
long long pref [200002];

int main ()
	{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>q;
	for (i=1; i<=n; i++)
		cin>>t[i];
	for (i=1; i<=n; i++)
		pref[i]=(pref[i-1]+t[i]);
	while (q--)
		{
		cin>>x;
		i=(lower_bound(pref,pref+n,x)-pref);
		cout<<i<<" "<<(x-pref[i-1])<<"\n";
		//printf ("%d %l64d\n",i,x-pref[i-1]);
		}
	return 0;
	}