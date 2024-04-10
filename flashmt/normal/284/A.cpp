#include <iostream>
using namespace std;

int main()
{
	int p, ans = 0;
	cin >> p;
	for (int i = 1; i <= p; i++)
	{
		int ok = 1, power = 1;
		for (int j = 1; j < p - 1; j++)
		{
			power = power * i % p;
			ok &= (power % p != 1);
		}
		if (power * i % p == 1 && ok) ans++;
	}
	cout << ans << endl;
}