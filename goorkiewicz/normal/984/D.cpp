#include <bits/stdc++.h>
using namespace std;

int q, n, i, j, len;
int t [5001][5001];
int out [5001][5001];

int main ()
	{
	scanf ("%d",&n);
	for (i=0; i<n; i++)
		{
		scanf ("%d",&t[i][i]);
		out[i][i]=t[i][i];
		}
	for (len=1; len<=n; len++)
		for (i=0; (i+len)<n; i++)
			{
			t[i][i+len]=(t[i][i+len-1]^t[i+1][i+len]);
			out[i][i+len]=max(t[i][i+len],max(out[i][i+len-1],out[i+1][i+len]));
			}
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d%d",&i,&j);
		printf ("%d\n",out[i-1][j-1]);
		}
	return 0;
	}