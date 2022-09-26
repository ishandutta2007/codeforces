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

int n,a,s;

ll ans;
ll v[2][1 << 20];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	v[0][0]++;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		s ^= a;
		v[i & 1][s]++;
	}
	for (int i = 0;i < (1 << 20);i++)
	{
		ans += v[0][i] * (v[0][i] - 1) / 2;
		ans += v[1][i] * (v[1][i] - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}