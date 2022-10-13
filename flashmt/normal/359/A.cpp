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
	int edge = 0, m, n, x;
	
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			if (!x) continue;
			if (i == 1 || i == m || j == 1 || j == n) edge = 1;
		}
		
	cout << (edge ? 2 : 4) << endl;
}