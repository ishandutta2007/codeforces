#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

long long n,m;

int main()
{
	cin >> n >> m;
	if (n >= 30)
	{
		cout << m << endl;
		return 0;
	}
	else
	{
		cout << m % (1ll << n) << endl;
		return 0;
	}
	return 0;
}