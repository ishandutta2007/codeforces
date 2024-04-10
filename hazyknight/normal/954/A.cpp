#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int n;
char c[105];

int main()
{
	cin >> n;
	getchar();
	for (int i = 1;i <= n;i++)
		c[i] = getchar();
	int ans = n;
	for (int i = 1;i < n;i++)
	{
		if (c[i] == 'U' && c[i + 1] == 'R')
			ans--,i++;
		else if (c[i] == 'R' && c[i + 1] == 'U')
			ans--,i++;
	}
	cout << ans << endl;
	return 0;
}