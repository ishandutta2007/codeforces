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
#include <bitset>

using namespace std;

int n,m,h;
int a[105];
int b[105];
int c[105][105];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> h;
	for (int i = 1;i <= m;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		cin >> b[i];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> c[i][j];
	for (int i = 1;i <= n;i++,cout << endl)
		for (int j = 1;j <= m;j++)
			if (c[i][j])
				cout << min(a[j],b[i]) << ' ';
			else
				cout << "0 ";
	return 0;
}