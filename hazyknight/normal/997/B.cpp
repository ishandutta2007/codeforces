#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <vector> 

using namespace std;

int n,ans;
bool mark[500005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	if (n <= 11)
	{
		for (int i = 0;i <= n;i++)
			for (int j = 0;i + j <= n;j++)
				for (int k = 0;i + j + k <= n;k++)
				{
					int l = n - i - j - k;
					mark[i + j * 5 + k * 10 + l * 50] = true;
				}
		for (int i = 1;i <= 50 * n;i++)
			if (!mark[i])
				ans++;
		cout << n * 50 - ans << endl;
	}
	else
		cout << (long long)n * 50 - 258 - (n - 11) << endl;
	return 0;
}