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

int m, n, row[111], col[111];
string a[111];

int main()
{
	cin >> n;
	m = n;
	for (int i = 0; i < m; i++) cin >> a[i];
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == '.')
				row[i] = col[j] = 1;
	
	int ok = 1;
	for (int i = 0; i < m; i++)
		if (!row[i]) ok = 0;
		
	if (ok)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (a[i][j] == '.')
				{
					cout << i + 1 << ' ' << j + 1 << endl;
					break;
				}
		return 0;
	}
		
	ok = 1;
	for (int i = 0; i < n; i++)
		if (!col[i]) ok = 0;
	
	if (ok)
	{
		for (int j = 0; j < n; j++)
			for (int i = 0; i < m; i++)
				if (a[i][j] == '.')
				{
					cout << i + 1 << ' ' << j + 1 << endl;
					break;
				}
		return 0;
	}
	
	puts("-1");
}