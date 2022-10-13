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
using namespace std;

int main()
{
	int n, ans = 0, x, y;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		if (y == 1) x++;
		else
			while (y > 1) y = (y + 3) / 4, x++;
		ans = max(ans, x);
	}
	
	cout << ans << endl;
}