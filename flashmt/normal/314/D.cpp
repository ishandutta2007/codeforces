#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const long long oo = 1LL << 60;

int n;
long long maxLeft[200200], maxRight[200200], minLeft[200200], minRight[200200];
pair <long long,long long> a[200100];

int possible(long long D)
{
	for (int i = 1, j = 0; i <= n; i++)
	{
		while (j + 1 <= n && a[j + 1].first - a[i].first <= D) j++;
		if (max(maxLeft[i - 1], maxRight[j + 1]) - min(minLeft[i - 1], minRight[j + 1]) <= D) return 1;
	}
	return 0;
}

int main()
{
	//freopen("d.in", "r", stdin);
	int x, y;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		a[i] = make_pair(x + y, x - y);
	}
	
	sort(a + 1, a + n + 1);
	minLeft[0] = minRight[n + 1] = oo;
	maxLeft[0] = maxRight[n + 1] = -oo;
	
	for (int i = 1; i <= n; i++)
	{
		minLeft[i] = min(minLeft[i - 1], a[i].second);
		maxLeft[i] = max(maxLeft[i - 1], a[i].second);
	}
	
	for (int i = n; i; i--)
	{
		minRight[i] = min(minRight[i + 1], a[i].second);
		maxRight[i] = max(maxRight[i + 1], a[i].second);
	}
		
	long long low = 0, high = oo, ans = high;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		if (possible(mid)) ans = mid, high = mid - 1;
		else low = mid + 1;
	}
	
	printf("%.9lf\n", 0.5 * ans);
}