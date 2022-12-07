#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, i, j, k, a, b, x, cnt;
ll out;
int A [N];
int B [N];
ll t [1000005];
bool del [N];

int main ()
	{
	scanf ("%d", &n);
	for (j=1; j<=n; j++)
		{
		scanf ("%d", &k);
		a = 1000000001;
		b = -1;
		for (i=1; i<=k; i++)
			{
			scanf ("%d", &x);
			if (x > a && del[j] == false)
				{
				del[j] = true;
				out += n;
				cnt++;
				}
			a = min(a, x);
			b = max(b, x);
			}

		if (del[j] == true)
			continue;
		
		A[j] = a;
		B[j] = b;
		}

	for (i=1; i<=n; i++)
		if (del[i] == false)
			t[B[i]]++;

	for (i=1000000; i>=1; i--)
		t[i] += t[i+1];
	
	for (i=1; i<=n; i++)
		if (del[i] == false)
			{
			out += t[A[i]+1];
			out += cnt;
			}
	printf ("%lld\n", out);
	return 0;
	}