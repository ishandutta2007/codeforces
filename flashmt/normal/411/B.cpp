#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, a[111][111], isMemoryLocked[111] = {0}, isCoreLocked[111] = {0};
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
			
	for (int j = 1; j <= m; j++)
	{
		int usedMemory[111] = {0};
		for (int i = 1; i <= n; i++)
		{
			if (isCoreLocked[i]) continue;
			if (a[i][j] && usedMemory[a[i][j]])
				isMemoryLocked[a[i][j]] = 1;
			usedMemory[a[i][j]] = 1;
		}
				
		for (int i = 1; i <= n; i++)
			if (isMemoryLocked[a[i][j]] && !isCoreLocked[i])
				isCoreLocked[i] = j;
	}
	
	for (int i = 1; i <= n; i++) cout << isCoreLocked[i] << endl;
}