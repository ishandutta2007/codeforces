#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 10, oo = 1000111000;

int n, a[N], isLevelReversed[22];
long long inversion[N * 8][2], levelInversion[22][2];
int *numbers[N * 8];

void build(int level, int nd, int l, int r)
{
	if (l == r)
	{
		numbers[nd] = new int[1];
		numbers[nd][0] = a[l];
	}
	else
	{
		int m = (l + r) / 2;
		build(level - 1, nd * 2, l, m);
		build(level - 1, nd * 2 + 1, m + 1, r);
		
		numbers[nd] = new int[r - l + 1];
		for (int i = 0, j = 0, k = 0, jj = 0, kk = 0; i < r - l + 1; i++)
		{
			int x = (j < m - l + 1 ? numbers[nd * 2][j] : oo);
			int y = (k < r - m ? numbers[nd * 2 + 1][k] : oo);
			
			if (x <= y) 
			{
				numbers[nd][i] = numbers[nd * 2][j++];
				
				while (kk < r - m && numbers[nd * 2 + 1][kk] < x) kk++;
				inversion[nd][0] += kk;
			}
			else 
			{
				numbers[nd][i] = numbers[nd * 2 + 1][k++];
				
				while (jj < m - l + 1 && numbers[nd * 2][jj] < y) jj++;
				inversion[nd][1] += jj;
			}
		}
		
		levelInversion[level][0] += inversion[nd][0];
		levelInversion[level][1] += inversion[nd][1];
	}
}

int main()
{

	cin >> n;
	for (int i = 0; i < 1 << n; i++) scanf("%d", a + i);
	
	build(n, 1, 0, (1 << n) - 1);
	
	int q, x;
	cin >> q;
	while (q--)
	{
		scanf("%d", &x);
		for (int i = 0; i <= x; i++) isLevelReversed[i] ^= 1;
		
		long long ans = 0;
		for (int i = 0; i <= n; i++) ans += levelInversion[i][isLevelReversed[i]];
		printf("%I64d\n", ans);
	}
}