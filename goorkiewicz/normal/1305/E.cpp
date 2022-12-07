#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const int N = 5005;
int n, m, i, j, sum;
int t [N];
int out [N];

int main ()
	{
	scanf ("%d%d", &n, &m);
	for (i=1; i<=n; i++)
		t[i] = (i-1)/2;

	for (i=1; i<=n; i++)
		{
		if (m >= t[i])
			{
			out[i] = i;
			m -= t[i];
			continue;
			}
		
		out[i] = i - 2 * m + i - 1;
		m = 0;
		break;
		}

	if (m != 0)
		return printf ("-1\n"), 0;

	for (i++; i<=n; i++)
		out[i] = 100000000 + 20000 * i;

	for (i=1; i<=n; i++)
		printf ("%d ", out[i]);
	printf ("\n");
	return 0;
	}