#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, i;
int t [5];
int cnt [5];
int out [N];

bool check (int s)
	{
	for (i=0; i<=3; i++)
		cnt[i] = t[i];
	out[1] = s;
	cnt[s]--;
	if (cnt[s]<0)
		return false;
	for (i=2; i<=n; i++)
		{
		if (cnt[out[i-1]-1] != 0)
			{
			out[i] = out[i-1]-1;
			cnt[out[i]]--;
			continue;
			}
		if (cnt[out[i-1]+1] != 0)
			{
			out[i] = out[i-1]+1;
			cnt[out[i]]--;
			continue;
			}
		return false;
		}
	return true;
	}

void answer()
	{
	printf ("YES\n");
	for (i=1; i<=n; i++)
		printf ("%d ", out[i]);
	printf ("\n");
	exit(0);
	}

int main ()
	{
	scanf ("%d%d%d%d", &t[0], &t[1], &t[2], &t[3]);
	n = t[0]+t[1]+t[2]+t[3];
	if (check(0) == true) answer();
	if (check(1) == true) answer();
	if (check(2) == true) answer();
	if (check(3) == true) answer();
	printf ("NO\n"); 
	return 0;
	}