#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
typedef long long ll;
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int k = 2; k <= n - 1; k++)
		{
			if (gcd(k, n - 1 - k) == 1)
			{
				cout << k << " " << n - 1 - k << " " << 1 << "\n";
				break;
			}
		}
	}
	return 0;
}