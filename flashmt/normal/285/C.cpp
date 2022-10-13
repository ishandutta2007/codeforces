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
using namespace std;
int n, a[300100];
int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) ans += abs(i + 1 - a[i]);
	cout << ans << endl;
}