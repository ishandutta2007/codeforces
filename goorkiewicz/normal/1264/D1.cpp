#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int N = 2005;
int n, i, a, b, len;
char t [N];
int dp [N][N];
int sum [N];

int pw2 (int b)
	{
	int a = 2;
	int res = 1;
	while (b!=0)
		{
		if (b%2==1)
			res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
		}
	return res;
	}

int qst (int a, int b) {
	return sum[b] - sum[a-1];
	}

int main ()
	{
	scanf ("%s", t+1);
	n = strlen(t+1);
	
	for (i=1; i<=n; i++)
		sum[i] = sum[i-1] + (t[i]=='?');

	for (len=1; len<=n; len++)
		{
		for (a=1; a+len<=n; a++)
			{
			b = a+len;
			//printf ("a=%d b=%d\n", a, b);
			if (t[a]==')')
				{
				dp[a][b] = dp[a+1][b];
				continue;
				}
			if (t[b]=='(')
				{
				dp[a][b] = dp[a][b-1];
				continue;
				}
			if (t[a]=='(' && t[b]==')')
				{
				dp[a][b] = dp[a+1][b-1] + pw2(qst(a+1, b-1));
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				continue;
				}
			if (t[a]=='(')
				{
				dp[a][b] += dp[a+1][b-1];
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				dp[a][b] += dp[a][b-1];
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				dp[a][b] += pw2(qst(a+1, b-1));
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				continue;
				}
			if (t[b]==')')
				{
				dp[a][b] += dp[a+1][b-1];
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				dp[a][b] += dp[a+1][b];
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				dp[a][b] += pw2(qst(a+1, b-1));
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				continue;
				}
			if (t[a]=='?' && t[b]=='?')
				{
				dp[a][b] += pw2(qst(a+1, b-1));
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				dp[a][b] += dp[a+1][b];
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				dp[a][b] += dp[a][b-1];
				if (dp[a][b]>=mod)
					dp[a][b]-=mod;
				continue;
				}
			}
		}
	
//	for (len=1; len<=n; len++)
//		{
//		for (a=1; a+len<=n; a++)
//			{
//			b = a+len;
//			printf ("dp[%d][%d] = %d\n", a, b, dp[a][b]);
//			}
//		}

	printf ("%d\n", dp[1][n]);
	return 0;
	}