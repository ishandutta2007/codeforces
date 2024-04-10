#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, ans[22][10100], p[10100];

int main()
{
	cin >> n >> k;
	for (int i = 0; i <= 10000; i++) p[i] = -1;
	for (int i = 0; 1 << i < 10000; i++) p[1 << i] = i;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
			if (p[j] >= 0) 
			{
				if (p[j] >= i) ans[i][j] = j;
				else ans[i][j] = 0;
			}
			else
				if (j > 0 && (j - 1) >> (i - 1) & 1) ans[i][j] = 1 << (i - 1);
				else ans[i][j] = 0;
	}
	
	for (int i = 1; i <= k; i++, puts(""))
		for (int j = n - 1; j >= 0; j--)
			printf("%d ", n - ans[i][j]);
}