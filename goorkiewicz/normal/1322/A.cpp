#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000005;
int n, i, j, out;
char s [N];
int bil [N];

int main ()
	{
	scanf ("%d", &n);
	scanf ("%s", s+1);
	
	for (i=1; i<=n; i++)
		{
		bil[i] = bil[i-1];
		if (s[i] == '(')
			bil[i]++;
		if (s[i] == ')')
			bil[i]--;
		}
	
	if (bil[n] != 0)
		return printf ("-1\n"), 0;

	for (i=1; i<=n; i++)
		if (s[i] == ')' && bil[i] < 0)
			out++;

	out *= 2;
	printf ("%d\n", out);

	return 0;
	}