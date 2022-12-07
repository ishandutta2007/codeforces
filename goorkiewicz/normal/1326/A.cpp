#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

int q, n, i, j;
vector <int> out, res;

void solve ()
	{
	scanf ("%d", &n);
	if (n == 1)
		{
		printf ("-1\n");
		return;
		}
	res.clear();
	for (i=0; i<n; i++)
		res.push_back(out[i]);
	reverse(res.begin(), res.end());
	for (int a : res)
		printf ("%d", a);
	printf ("\n");
	}

int main ()
	{
	scanf ("%d", &q);
	
	out.push_back(3);
	out.push_back(2);
	
	while (out.size() <= 100005)
		out.push_back(6);

	while (q--)
		solve();
	return 0;
	}