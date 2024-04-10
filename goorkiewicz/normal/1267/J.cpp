#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000005;
const int inf = 100000001;
int n, i, j, out;
int t [N];
int cnt [N];
int val [N];
vector <int> vec;

int check (int s)
	{
	int k;
	int res = 0;
	for (int a : vec)
		{
		k = (a+s-1)/s;
		res += k * val[a];
		if (s*k - a > k)
			return inf;
		}
	
//	printf ("check %d -> %d\n", s, res);
	return res;
	}

void solve ()
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++)
		{
		int x;
		scanf ("%d", &t[i]);
		cnt[t[i]]++;
		}

	for (i=1; i<=n; i++)
		val[cnt[i]]++;

	vec.clear();
	for (i=1; i<=n; i++)
		if (val[i] > 0)
			vec.push_back(i);
	
//	for (int a  : vec)
//		printf ("> %d\n", a);

	out = inf;
	for (i=1; i<=n; i++)
		out = min(out, check(i));

	printf ("%d\n", out);
	
	for (i=1; i<=n; i++)
		val[cnt[i]]--;
	for (i=1; i<=n; i++)
		cnt[t[i]]--;
	}

int main ()
	{
	int q;
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}