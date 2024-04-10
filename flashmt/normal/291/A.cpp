#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n, x, ans = 0;
	map <int,int> m;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (!x) continue;
		if (++m[x] > 2)
		{
			ans = -1; break;
		}
		if (m[x] == 2) ans++;
	}
	cout << ans << endl;
}