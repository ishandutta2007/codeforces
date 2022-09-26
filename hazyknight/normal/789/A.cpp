#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int n,k,ans;

int main()
{
	cin >> n >> k;
	for (int i = 1,a;i <= n;i++)
	{
		cin >> a;
		ans += ((a % k == 0) ? a / k : a / k + 1);
	}
	cout << ((ans + 1) >> 1) << endl;
	return 0;
}