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

int n, m, b[1000100];
long long a[33], c[33];

int possible(int M)
{
	for (int i = 0; i < 30; i++) c[i] = a[i];
	for (int i = 0; i < M; i++) c[b[i]]--;
	for (int i = 29; i >= 0; i--)
		if (c[i] < 0) return 0;
		else 
			if (i) c[i - 1] += c[i] * 2;
	return 1;
}

int main()
{
	int x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &x);
		for (int j = 0; j < 30; j++)
			if (x >> j & 1) a[j]++;
	}
	for (int i = 0; i < m; i++) scanf("%d", b + i);
	sort(b, b + m);
	
	int low = 1, high = m, ans = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (possible(mid)) ans = mid, low = mid + 1;
		else high = mid - 1;
	}
	
	cout << ans << endl;
}