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

typedef double db;

const int MAXN = 105;

int n,tot;

db ans;
db a[MAXN];
db P[MAXN];
db ANS[300005];

pair<db,int> v[MAXN];

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		a[i] = a[i] / 100;
	}
	for (int i = 0;i < n;i++)
		P[i] = (1 - a[i]);
	db PP = 1;
	for (int i = 0;i < n;i++)
		PP *= 1 - P[i];
	ANS[n] = PP;
	for (int i = n;i < 300000;i++)
	{
		for (int j = 0;j < n;j++)
			v[j] = make_pair((1 - P[j] * (1 - a[j])) / (1 - P[j]),j);
		int c = 0;
		for (int j = 1;j < n;j++)
			if (v[j].first > v[c].first)
				c = j;
		P[c] *= (1 - a[c]);
		PP = 1;
		for (int j = 0;j < n;j++)
			PP *= 1 - P[j];
		ANS[i + 1] = PP;
	}
	for (int i = n;i <= 300000;i++)
		ans += (ANS[i] - ANS[i - 1]) * i;
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}