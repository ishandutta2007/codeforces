#include <iostream>
#include <cstdio>

#define MAXM 152
#define MAXN 152

using namespace std;

typedef long long lint;

const lint M = 1000000007;
int n, m;
lint dp[MAXN][MAXM][MAXM][2][2];
lint dpsum[2][2][MAXM][MAXM];

lint get2(int il, int dr, int l, int r)
{
	if (l < 0 || r < 0)
		return 0;
	return dpsum[il][dr][l][r];
}

void calc_dpsum(int i, int il, int dr)
{
	for (int l = 0; l < m; l++)
		for (int r = 0; r < m; r++)
			dpsum[il][dr][l][r] = dp[i][l][r][il][dr] + get2(il, dr, l-1, r) + get2(il, dr, l, r-1) - get2(il, dr, l-1, r-1);
}

lint get(int i, int l1, int l2, int r1, int r2, int il, int dr) {
	lint ret = get2(il, dr, l2, r2) -
		get2(il, dr, l1-1, r2) -
		get2(il, dr, l2, r1-1) +
		get2(il, dr, l1-1, r1-1);
	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int l = 0; l < m; l++)
		for (int r = 0; r < m; r++)
			for (int il = 0; il < 2; il++)
				for (int dr = 0; dr < 2; dr++)
					dp[n-1][l][r][il][dr] = l <= r;
	for (int il = 0; il < 2; il++)
		for (int dr = 0; dr < 2; dr++)
			calc_dpsum(n-1, il, dr);
	
	for (int i = n-2; i >= 0; i--) {
		for (int l = 0; l < m; l++)
			for (int r = 0; r < m; r++)
				for (int il = 0; il < 2; il++)
					for (int dr = 0; dr < 2; dr++) {
						dp[i][l][r][il][dr] = 0;
						if (r < l) continue;
						dp[i][l][r][il][dr] = 1;
						dp[i][l][r][il][dr] = (dp[i][l][r][il][dr] + get(i+1, (il ? l : 0), l, l, r-1, il, 1))%M;
						dp[i][l][r][il][dr] = (dp[i][l][r][il][dr] + get(i+1, (il ? l : 0), l, r, (dr ? r : m-1), il, dr))%M;
						dp[i][l][r][il][dr] = (dp[i][l][r][il][dr] + get(i+1, l+1, r, l, r-1, 1, 1))%M;
						dp[i][l][r][il][dr] = (dp[i][l][r][il][dr] + get(i+1, l+1, r, r, (dr ? r : m-1), 1, dr))%M;
					}
		for (int il = 0; il < 2; il++)
			for (int dr = 0; dr < 2; dr++)
				calc_dpsum(i, il, dr);
	}

	lint ret = 0;

	for (int i = 0; i < n; i++)
		for (int l = 0; l < m; l++)
			for (int r = l; r < m; r++)
				ret = (ret + dp[i][l][r][0][0])%M;

	printf("%d\n", (int)ret);

	return 0;
}