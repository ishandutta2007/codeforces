#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n;
int a[10005];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	int cur = 1,cnt = 0;
	while (cur <= n)
	{
		cnt++;
		int MAX = a[cur];
		while (cur <= MAX)
		{
			MAX = max(MAX,a[cur]);
			cur++;
		}
	}
	cout << cnt << endl;
	return 0;
}