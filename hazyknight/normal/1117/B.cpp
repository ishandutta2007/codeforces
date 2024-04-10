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

typedef long long ll;

const int MAXN = 200005;

int n;

ll m,k;
ll a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	cout << (m / (k + 1)) * (a[n] * k + a[n - 1]) + (m % (k + 1)) * a[n] << endl;
	return 0;
}