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

int main()
{
	int n, k, t, f, ans = - (1 << 30);
	cin >> n >> k;
	while (n--)
	{
		cin >> f >> t;
		if (t > k) ans = max(ans, f - (t - k));
		else ans = max(ans, f);
	}
	cout << ans << endl;
}