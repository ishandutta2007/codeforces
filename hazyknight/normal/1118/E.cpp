#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 200005;

int n,m,preb,preg;

void add(int b,int g)
{
	if (b == preb || g == preg)
		swap(b,g);
	cout << b << ' ' << g << endl;
	preb = b;
	preg = g;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if ((long long)m * (m - 1) < n)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1;i <= m && n;i++)
		for (int j = i + 1;j <= m && n;j++)
		{
			add(i,j);
			n--;
			if (n)
			{
				add(i,j);
				n--;
			}
		}
	return 0;
}