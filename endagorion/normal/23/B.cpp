#include <iostream>
#include <cstdio>

using namespace std;

int a[5] = {0, 0, 0, 1, 2};

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 1) cout << 0 << '\n';
			else cout << n-2 << '\n';
	}
	
	return 0;
}