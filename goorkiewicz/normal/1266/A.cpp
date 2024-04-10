#include <bits/stdc++.h>
using namespace std;

const int N = 502;
int q, n, i, x, sum;
char a [N];
int cnt [11];

bool solve ()
	{
	scanf ("%s", a+1);
	for (i=0; i<10; i++)
		cnt[i] = 0;
	
	n = strlen(a+1);

	for (i=1; i<=n; i++)
		cnt[a[i]-'0']++;
	
	x = 0;
	sum = 0;
	for (i=1; i<10; i++)
		{
		sum += cnt[i] * i;
		if (i%2==0) x += cnt[i];
		}
	if (sum%3==0)
		{
		if (cnt[0] > 1)
			return true;
		if (cnt[0] > 0 && x > 0)
			return true;
		}
	return false;
	}

int main ()
	{
	scanf("%d", &q);
	while (q--)
		printf ("%s\n", solve() ? "red" : "cyan");
	return 0;
	}