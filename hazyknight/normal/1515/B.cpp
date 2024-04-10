#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int T,n;

int sq(int x)
{
	int t = sqrt(x);
	while (t * t < x)
		t++;
	while (t * t > x)
		t--;
	return t;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n % 2 != 0)
		{
			puts("NO");
			continue;
		}
		int S = n / 2,tt = sq(S);
		if (tt * tt == S)
		{
			puts("YES");
			continue;
		}
		tt = sq(S / 2);
		if (tt * tt * 2 == S)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}