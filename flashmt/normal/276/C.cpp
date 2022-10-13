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

int d[200200], n, a[200200];

int main()
{
	int Q, x, y;
	cin >> n >> Q;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	
	while (Q--) scanf("%d%d", &x, &y), d[--x]++, d[y]--;
	for (int i = 1; i < n; i++) d[i] += d[i - 1];
	sort(d, d + n);
	
	long long ans = 0;
	for (int i = 0; i < n; i++) ans += 1LL * a[i] * d[i];
	cout << ans << endl;
}