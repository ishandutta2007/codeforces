#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n,pos,l,r;
	cin >> n >> pos >> l >> r;
	if (l == 1 && r == n)
		cout << 0 << endl;
	else if (l == 1)
		cout << abs(pos - r) + 1 << endl;
	else if (r == n)
		cout << abs(pos - l) + 1 << endl;
	else
		cout << min(abs(pos - l) + 1 + abs(r - l) + 1,abs(pos - r) + 1 + abs(r - l) + 1) << endl;
	return 0;
}