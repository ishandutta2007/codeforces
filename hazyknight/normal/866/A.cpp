#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int n;

int main()
{
	cin >> n;
	if (n == 1)
	{
		cout << 1 << ' ' << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	cout << 2 * n - 2 << ' ' << 2 << endl;
	cout << "1 2" << endl;
	return 0;
}