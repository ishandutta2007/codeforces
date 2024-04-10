#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int main()
{
	int n, x, a[8] = {0}, zero = 0;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (!x)
		{
			zero++; continue;
		}
		int mask = 0, tmp = x;
		for (int i = 0; i < 3; i++, x /= 10)
			if (x % 10) mask |= 1 << i;
		a[mask] = tmp;
	}
	
	if (a[1] && a[2] && a[4])
	{
		cout << zero + 3 << endl;
		while (zero--) cout << 0 << ' ';
		cout << a[1] << ' ' << a[2] << ' ' << a[4] << endl;
		return 0;
	}
	
	for (int i = 1; i < 8; i++)
		for (int j = i + 1; j < 8; j++)
			if ((i & j) == 0 && a[i] && a[j])
			{
				cout << zero + 2 << endl;
				while (zero--) cout << 0 << ' ';
				cout << a[i] << ' ' << a[j] << endl;
				return 0;
			}
			
	for (int i = 1; i < 8; i++)
		if (a[i])
		{
			cout << zero + 1 << endl;
			while (zero--) cout << 0 << ' ';
			cout << a[i] << endl;
			return 0;
		}
		
	cout << zero << endl;
	while (zero--) cout << 0 << ' ';
}