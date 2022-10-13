#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int a, b, c, x, y, z, n;
	cin >> a >> b >> c >> x >> y >> z >> n;
	cout << (n >= (a + b + c + 4) / 5 + (x + y + z + 9) / 10 ? "YES" : "NO") << endl;
}