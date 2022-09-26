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
#include <fstream>

using namespace std;

const int MAXN = 1000005;

int n;
int a[MAXN];
int c[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
		scanf("%d",&c[i]);
	if (a[1] != c[1] || a[n] != c[n])
	{
		cout << "No" << endl;
		return 0;
	}
	for (int i = n;i >= 2;i--)
	{
		a[i] -= a[i - 1];
		c[i] -= c[i - 1];
	}
	sort(a + 2,a + n + 1);
	sort(c + 2,c + n + 1);
	for (int i = 2;i <= n;i++)
		if (a[i] != c[i])
		{
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	return 0;
}