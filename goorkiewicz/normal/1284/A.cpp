
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 22;
int n1, n2, k1, k2, i, q, y;
char a [N][1005];
char b [N][1005];
string s1, s2;

int main()
	{
	scanf ("%d%d", &n1, &n2);

	for (i=0; i<n1; i++)
		scanf ("%s", a[i]);

	for (i=0; i<n2; i++)
		scanf ("%s", b[i]);

	scanf ("%d", &q);

	while (q--)
		{
		scanf ("%d", &y);
		
		k1 = (y-1)%n1;
		k2 = (y-1)%n2;

		for (i=0; a[k1][i]!=0; i++)
			printf ("%c", a[k1][i]);
		
		for (i=0; b[k2][i]!=0; i++)
			printf ("%c", b[k2][i]);
		
		printf ("\n");
		}
	return 0;
	}