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

int n, k, s[500500];

int main()
{
	int x;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> x, s[i] = s[i - 1] + x;
	
	int ans = k;
	for (int i = k + 1; i <= n; i++)
		if (s[i] - s[i - k] < s[ans] - s[ans - k])
			ans = i;
	
	cout << ans - k + 1 << endl;
}