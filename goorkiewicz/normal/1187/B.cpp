#include <bits/stdc++.h>
using namespace std;

int n, q, i, out;
char c;
int cnt [257];
char s [1000001];
char a [1000001];
vector <int> v [257];

int main ()
	{
	scanf ("%d%s%d",&n,s+1,&q);
	for (i=1; i<=n; i++)
		v[s[i]].push_back(i);
	while (q--)
		{
		scanf ("%s",a+1);
		n = strlen(a+1);
		for (c='a'; c<='z'; c++)
			cnt[c] = 0;
		for (i=1; i<=n; i++)
			cnt[a[i]]++;
		out = 0;
		for (c='a'; c<='z'; c++)
			if (cnt[c]>=1)
				out = max(out, v[c][cnt[c]-1]);
		printf ("%d\n",out);
		}
	return 0;
	}