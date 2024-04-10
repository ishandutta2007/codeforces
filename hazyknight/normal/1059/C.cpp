#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	if (n == 1)
	{
		cout << "1" << endl;
		return 0;
	}
	int last = n;
	for (int i = 2;(i / 2) <= n;i <<= 1)
	{
		if (last == 3)
		{
			cout << i / 2 << ' ' << i / 2 << ' ' << i + i / 2 << endl;
			break;
		}
		for (int j = i / 2;j <= n;j += i)
			cout << i / 2 << ' ',last--;
	}
	cout << endl;
	return 0;
}