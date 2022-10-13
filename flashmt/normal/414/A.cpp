#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	if (k < n / 2) cout << -1 << endl;
	else
	{
		if (n == 1)
		{
			cout << (k ? -1 : 1) << endl;
			return 0;
		}
		
		set <int> usedNumbers;
		int x = k - n / 2 + 1;
		cout << x << ' ' << x * 2 << ' ';
		usedNumbers.insert(x);
		usedNumbers.insert(x * 2);
		n -= 2;
		for (int i = 3; n; i += 2) 
			if (!usedNumbers.count(i))
				cout << i << ' ', n--;
	}
}