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
#include <sstream>
#include <cstdlib>
using namespace std;

int n, a[100100], r[100100];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	int ans = -1;
	r[n - 1] = n; a[n] = 1 << 30;
	
	for (int i = n - 2; i >= 0; i--)
	{
		r[i] = i + 1;
		while (r[i] < n && a[i] > a[r[i]])
		{
			ans = max(ans, a[i] ^ a[r[i]]);
			r[i] = r[r[i]];
		}
		if (r[i] < n) ans = max(ans, a[i] ^ a[r[i]]);
	}
	cout << ans << endl;
}