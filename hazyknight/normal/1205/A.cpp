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

const int MAXN = 100005;

int n;
int a[MAXN << 1];

int main()
{
	scanf("%d",&n);
	if (~n & 1)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 1;i <= n;i++)
	{
		a[i] = i * 2 - 1;
		a[i + n] = i * 2;
		if (i & 1)
			swap(a[i],a[i + n]);
	}
	for (int i = 1;i <= 2 * n;i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}