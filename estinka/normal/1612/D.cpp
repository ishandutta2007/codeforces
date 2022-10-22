#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
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
		ll a, b, x;
		cin >> a >> b >> x;
		bool m = false;
		if (a > b) swap(a, b);
		while (a)
		{
			ll c = b % a;
			if (c <= x && x <= b && (b - x) % a == 0)
			{
				m = true;
				break;
			}
			b = a;
			a = c;
		}
		cout << (m ? "YES\n" : "NO\n");
		/*set<ll> s;
		for (int i = 0; i < (1 << 10); i++)
		{
			ll ai = a, bi = b;
			for (int j = 0; j < 10; j++)
			{
				if (i & (1 << j)) ai = abs(ai - bi);
				else bi = abs(bi - ai);
			}
			//cout << "(" << ai << ", " << bi << ")\n";
			s.insert(ai);
			s.insert(bi);
		}
		for (ll i : s) cout << i << " ";
		cout << "\n";*/
	}
	return 0;
}