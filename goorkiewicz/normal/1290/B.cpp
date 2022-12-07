#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int n, i, q, a, b, c, cnt;
char s [N];
int t [30][N];

int main ()
	{
	scanf ("%s", s+1);
	
	n = strlen(s+1);
	
	for (i=1; i<=n; i++)
		{
		s[i] -= 'a';
		t[s[i]][i]++;
		}
	
	for (c=0; c<='z'-'a'; c++)
		for (i=1; i<=n; i++)
			t[c][i] += t[c][i-1];
	
	scanf ("%d", &q);
	while (q--)
		{
		scanf ("%d%d", &a, &b);
		
		if (a == b)
			{
			printf ("Yes\n");
			continue;
			}
		
		if (s[a] != s[b])
			{
			printf ("Yes\n");
			continue;
			}
		
		a--;
		cnt = 0;
		for (c=0; c<='z'-'a'; c++)
			if (t[c][b] - t[c][a] != 0)
				cnt++;

		if (cnt <= 2)
			{
			printf ("No\n");
			continue;
			}
		
		printf ("Yes\n");
		}
	return 0;
	}