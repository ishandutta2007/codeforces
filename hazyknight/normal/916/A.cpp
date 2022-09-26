#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int x,h,m;
int cnt;

bool lucky()
{
	if (h % 10 == 7 || m % 10 == 7)
		return true;
	return false;
}

void getnext()
{
	cnt++;
	if (h == 0 && m == 0)
		h = 23,m = 59;
	else if (m == 0)
		h--,m = 59;
	else
		m--;
}

int main()
{
	cin >> x >> h >> m;
	while (1)
	{
		if (cnt % x == 0 && lucky())
		{
			cout << cnt / x << endl;
			return 0;
		}
		getnext();
	}
	return 0;
}