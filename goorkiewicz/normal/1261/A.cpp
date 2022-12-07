#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005;
int q, n, k, i, j;
char t [N];
char p [N];
vector < pair <int,int> > out;

int main ()
	{
	scanf ("%d", &q);
	while (q--)
		{
		scanf ("%d%d", &n, &k);
		scanf ("%s", t+1);
		k--;
		for (i=1; i<=n; i++)
			p[i] = 0;
		for (i=1; i<=2*k; i+=2)
			{
			p[i] = '(';
			p[i+1] = ')';
			}
		
		j = i;
		
		for (i=j; i<=n; i++)
			{
			if (p[i]!=0)
				break;
			p[i] = '(';
			p[n-(i-j)] = ')';
			}
		
		//printf (">> %s\n",p+1);
		
		out.clear();
		for (i=1; i<=n; i++)
			{
			if (t[i]==p[i])
				continue;

			for (j=i; j<=n; j++)
				if (t[j]==p[i])
					break;
			
			out.push_back({i, j});
			reverse(t+i, t+j+1);
			}
		
		printf ("%d\n", (int)(out.size()));
		for (pair <int,int> a : out)
			printf ("%d %d\n", a.first, a.second);
		}
	return 0;
	}