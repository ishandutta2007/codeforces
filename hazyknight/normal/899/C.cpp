#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	if (n % 4 == 0)
	{
		cout << 0 << endl;
		cout << n / 2 << ' ';
		for (int i = 1;i <= n / 2;i += 2)
			cout << i << ' ';
		for (int i = n;i >= n / 2 + 1;i -= 2)
			cout << i << ' ';
		cout << endl;
	}
	if (n % 4 == 1)
	{
		cout << 1 << endl;
		n--;
		cout << n / 2 << ' ';
		for (int i = 1;i <= n / 2;i += 2)
			cout << i + 1 << ' ';
		for (int i = n;i >= n / 2 + 1;i -= 2)
			cout << i + 1 << ' ';
		cout << endl;
	}
	if (n % 4 == 2)
	{
		cout << 1 << endl;
		n -= 2;
		cout << n / 2 + 1 << ' ' << 1 << ' ';
		for (int i = 1;i <= n / 2;i += 2)
			cout << i + 2 << ' ';
		for (int i = n;i >= n / 2 + 1;i -= 2)
			cout << i + 2 << ' ';
		cout << endl;
	}
	if (n % 4 == 3)
	{
		cout << 0 << endl;
		n -= 3;
		cout << n / 2 + 1 << ' ' << 3 << ' ';
		for (int i = 1;i <= n / 2;i += 2)
			cout << i + 3 << ' ';
		for (int i = n;i >= n / 2 + 1;i -= 2)
			cout << i + 3 << ' ';
		cout << endl;
	}
	return 0;
}