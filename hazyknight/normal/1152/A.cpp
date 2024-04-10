#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,m,a;
int cnta[2];
int cntb[2];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		cnta[a & 1]++;
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> a;
		cntb[a & 1]++;
	}
	cout << min(cnta[0],cntb[1]) + min(cnta[1],cntb[0]) << endl;
	return 0;
}