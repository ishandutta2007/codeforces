#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char m;
int n, i;
char a [500005];

int main ()
	{
	scanf ("%s",a+1);
	n = strlen(a+1);
	m = 'z'+1;
	for (i=1; i<=n; i++)
		{
		m = min(m, a[i]);
		if (a[i]==m)
			printf ("Mike\n");
		else
			printf ("Ann\n");
		}
	return 0;
	}