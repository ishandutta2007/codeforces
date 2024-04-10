#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <iomanip>
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
		int a, b, c;
		cin >> a >> b >> c;
		ll num = stoi(string(c, '9'));
		ll na = num, nb = num;
		while (to_string(na).size() < a) na *= 2;
		while (to_string(nb).size() < b) nb *= 3;
		cout << na << " " << nb << "\n";
	}
	return 0;
}