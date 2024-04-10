#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

const int MAXN = 1005;

int n;
int x[MAXN];
int y[MAXN];
int a[MAXN];
int b[MAXN];

map<pair<int,int>,int> match;

bool ok(int X,int Y)
{
	match.clear();
	for (int i = 1;i <= n;i++)
		match[make_pair(x[i],y[i])]++;
	for (int i = 1;i <= n;i++)
	{
		if (!match[make_pair(X - a[i],Y - b[i])])
			return false;
		match[make_pair(X - a[i],Y - b[i])]--;
	}
	return true;
}

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> x[i] >> y[i];
	for (int i = 1;i <= n;i++)
		cin >> a[i] >> b[i];
	for (int i = 1;i <= n;i++)
		if (ok(a[1] + x[i],b[1] + y[i]))
		{
			cout << a[1] + x[i] << ' ' << b[1] + y[i] << endl;
			return 0;
		}
	return 0;
}