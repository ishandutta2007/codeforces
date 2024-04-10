#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1;;i += 2)
	{
		cout << i << ' ' << 0 << endl;
		n--;
		if (!n)
			return 0;
		cout << i + 1 << ' ' << 0 << endl;
		n--;
		if (!n)
			return 0;
		cout << i + 1 << ' ' << 3 << endl;
		n--;
		if (!n)
			return 0;
	}
	return 0;
}