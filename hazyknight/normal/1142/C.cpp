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

const int MAXN = 100005;

int n,top;
int S[MAXN];

pair<ll,ll> a[MAXN];

ll cross(ll xa,ll ya,ll xb,ll yb,ll xc,ll yc)
{
	return xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].first >> a[i].second;
		a[i].second -= a[i].first * a[i].first;
	}
	sort(a + 1,a + n + 1);
	S[++top] = 1;
	for (int i = 2;i <= n;i++)
	{
		while (top >= 1 && a[i].first == a[S[top]].first)
			top--;
		while (top > 1 && cross(a[S[top - 1]].first,a[S[top - 1]].second,a[S[top]].first,a[S[top]].second,a[i].first,a[i].second) >= 0)
			top--;
		S[++top] = i;
	}
	cout << top - 1 << endl;
	return 0;
}