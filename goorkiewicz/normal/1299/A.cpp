#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, i, j, k;
int t [N];
int cnt [30];
int val [N];
pair <int,int> out;

int main () 
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++)
		scanf ("%d", &t[i]);

	for (i=1; i<=n; i++)
		for (k=0; k<30; k++)
			if ((t[i]>>k)&1)
				cnt[k]++;
	
	for (i=1; i<=n; i++)
		for (k=0; k<30; k++)
			if (((t[i]>>k)&1) && cnt[k] == 1)
				val[i] ^= (1<<k);
		
	j = 1;
	for (i=1; i<=n; i++)
		if (val[i] > val[j])
			j = i;
	
	swap(t[1], t[j]);
	for (i=1; i<=n; i++)
		printf ("%d ", t[i]);
	printf ("\n");
	return 0;
	}