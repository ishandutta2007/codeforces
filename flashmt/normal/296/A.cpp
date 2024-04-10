#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, x, d[1010] = {0}, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x, mx = max(mx, ++d[x]);
	cout << (mx * 2 <= n + 1 ? "YES" : "NO") << endl;
}