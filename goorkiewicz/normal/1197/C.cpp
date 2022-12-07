#include <bits/stdc++.h>
using namespace std;

int n, k, i, out;
int t [300005];
vector <int> s;

int main ()
	{
	scanf ("%d%d",&n,&k);
	for (i=1; i<=n; i++)
		scanf ("%d",&t[i]);
	for (i=1; i<n; i++)
		s.push_back(t[i+1]-t[i]);
	sort(s.begin(), s.end());
	k--;
	while (k--)
		s.pop_back();
	for (int a : s)
		out+=a;
	printf ("%d\n",out);
	return 0;
	}