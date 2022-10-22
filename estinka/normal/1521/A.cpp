#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		if (b == 1)
		{
			cout << "NO\n";
		}
		else cout << "YES\n" << a * b << " " << a << " " << (b + 1) * a << "\n";
		// if b != 1, a is not divisible by a * b and (b + 1) * a too.
	}
	return 0;
}