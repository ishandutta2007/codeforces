#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int N = 5005;
int n, i, j, k, d;
int out1, out2;
int t [N];
int F [N];
int H [N];
bool del [N];
vector <int> L [N];
vector <int> R [N];
vector <int> v [N];
vector <int> LZ [N];
vector <int> RZ [N];

void solve (int Z)
	{
	int i, j, a, b;
	
	int res1 = 0;
	int res2 = 1;
	
	if (d != 0)
		{
		res1++;
		j = (upper_bound(RZ[F[d]].begin(), RZ[F[d]].end(), Z) - RZ[F[d]].begin());
		j = RZ[F[d]].size() - j;
		if (R[F[d]][H[d]] > Z)
			j--;
		if (j > 0)
			{
			res1 += 1;
			res2 = (1ll * res2 * j) % mod;
			}
		}
	
	for (i=1; i<=n; i++)
		{
		if (i == F[d])
			continue;
		
		b = (upper_bound(RZ[i].begin(), RZ[i].end(), Z) - RZ[i].begin());
		b = RZ[i].size() - b;
		
		a = (lower_bound(LZ[i].begin(), LZ[i].end(), Z) - LZ[i].begin());
		
		if (a > b)
			swap(a, b);

		if (a == 0 && b == 0)
			continue;

		if (a == 0)
			{
			res1 += 1;
			res2 = (1ll * res2 * b) % mod;
			continue;
			}

		if (a == 1 && b == 1)
			{
			res1 += 1;
			res2 = (1ll * res2 * (a + b)) % mod;
			continue;
			}

		res1 += 2;
		res2 = (1ll * res2 * a) % mod;
		res2 = (1ll * res2 * (b-1)) % mod;
		}
	
//	printf ("Z=%d r1=%d r2=%d\n\n", Z, res1, res2);

	if (res1 > out1)
		{
		out1 = res1;
		out2 = res2;
		return;
		}

	if (res1 == out1)
		out2 = (out2 + res2) % mod;
	}

int main ()
	{
	scanf ("%d%d", &n, &k);
	
	for (i=1; i<=n; i++)
		{
		scanf ("%d", &t[i]);
		L[t[i]].push_back(i);
		R[t[i]].push_back(i);
		}
	
	for (i=1; i<=n; i++)
		reverse(R[i].begin(), R[i].end());
	
	for (i=1; i<=k; i++)
		{
		scanf ("%d%d", &F[i], &H[i]);
		H[i]--;
		if (H[i] >= L[F[i]].size())
			{
			del[i] = true;
			continue;
			}
		LZ[F[i]].push_back(L[F[i]][H[i]]);
		RZ[F[i]].push_back(R[F[i]][H[i]]);
		}
	
	for (i=1; i<=n; i++)
		{
		sort(LZ[i].begin(), LZ[i].end());
		sort(RZ[i].begin(), RZ[i].end());
		}

	d = 0;
	solve(0);
	
	for (i=1; i<=k; i++)
		{
		if (del[i] == true)
			continue;
		d = i;
		solve(L[F[i]][H[i]]);
		}
	
	printf ("%d %d\n", out1, out2);
	return 0;
	}