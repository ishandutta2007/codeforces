#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int n,m;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int cur = 0;
	for (int a,i = 1;i <= n;i++)
	{
		cin >> a;
		cur += a;
		cout << cur / m << ' ';
		cur %= m;
	}
	cout << endl;
	return 0;
}