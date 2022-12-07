#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105;
int n, i, j, out;
int t [N];
int T [N];
int CNT [2];
int cnt [2];
vector <int> sp [2];

void check (int a, int b)
	{
	for (i=1; i<=n; i++)
		t[i] = T[i];

	if (t[1]!=0 && t[1]%2!=a%2)
		return;
	if (t[n]!=0 && t[n]%2!=b%2)
		return;
	
	cnt[0] = CNT[0];
	cnt[1] = CNT[1];

	if (t[1]==0) cnt[a%2]--;
	if (t[n]==0) cnt[b%2]--;
	
	t[1] = a;
	t[n] = b;
	
	if (cnt[0] < 0) return;
	if (cnt[1] < 0) return;

	sp[0].clear();
	sp[1].clear();
	
	int res = 0;
	for (i=1; i<n; i++)
		{
		if (t[i]!=0)
			{
			for (j=i+1; j<=n; j++)
				if (t[j]!=0)
					break;
			
			if (t[i]%2 != t[j]%2)
				{
				res++;
				continue;
				}

			if (j != i+1)
				{
				res += 2;
				sp[t[i]%2].push_back(j - i - 1);
				}
			}
		}
	
	sort(sp[0].begin(), sp[0].end());
	sort(sp[1].begin(), sp[1].end());
	reverse(sp[0].begin(), sp[0].end());
	reverse(sp[1].begin(), sp[1].end());
	
	while (!sp[0].empty() && sp[0].back() <= cnt[0])
		{
		res -= 2;
		cnt[0] -= sp[0].back();
		sp[0].pop_back();
		}
	
	while (!sp[1].empty() && sp[1].back() <= cnt[1])
		{
		res -= 2;
		cnt[1] -= sp[1].back();
		sp[1].pop_back();
		}

	out = min(out, res);
	}

int main ()
	{
	scanf ("%d", &n);

	CNT[0] = n/2;
	CNT[1] = (n+1)/2;
	for (i=1; i<=n; i++)
		{
		scanf ("%d", &T[i]);
		if (T[i]!=0)
			CNT[T[i]%2]--;
		}
	
	if (n==1)
		return printf ("0\n"), 0;

	out = 1000000001;
	
	check(1, 1);
	check(1, 2);
	check(2, 1);
	check(2, 2);
	
	printf ("%d\n", out);
	return 0;
	}