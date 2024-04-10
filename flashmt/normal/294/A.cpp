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
	int n, m, x, y, a[111];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	cin >> m;
	while (m--)
	{
		cin >> x >> y;
		a[x - 1] += y - 1;
		a[x + 1] += a[x] - y;
		a[x] = 0;
	}
	
	for (int i = 1; i <= n; i++) cout << a[i] << endl;
}