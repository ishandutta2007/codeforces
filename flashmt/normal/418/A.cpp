#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	
	int matches = n * k, totalMatches = n * (n - 1) / 2;
	
	if (matches > totalMatches)
	{
		cout << -1 << endl;
		return 0;
	}	
	
	cout << matches << endl;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= i + k; j++) cout << i << ' ' << (j <= n ? j : j - n) << endl;
}