#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

int cnt;

bool check(int h,int m)
{
	return (h % 10 == m / 10) && (h / 10 == m % 10);
}

int main()
{
	int h,m;
	scanf("%2d:%2d",&h,&m);
	while (!check(h,m))
	{
		m++;
		if (m == 60)
		{
			m = 0;
			h++;
		}
		if (h == 24)
			h = 0;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}