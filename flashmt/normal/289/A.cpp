#include <iostream>
using namespace std;

int main()
{
	int n, x, y, s = 0, k;
	cin >> n >> k;
	while (n--) cin >> x >> y, s += y - x + 1, s %= k;
	cout << (s ? k - s : 0) << endl;
}