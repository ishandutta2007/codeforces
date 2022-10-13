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
	int n, x, ans = 0, cntNeg = 0, maxNeg = -12345;
	vector <int> a;
	cin >> n;
	for (int i = 0; i < n * 2 - 1; i++)
	{
		cin >> x;
		a.push_back(x);
		ans += abs(x);
		if (x < 0) cntNeg++, maxNeg = max(maxNeg, x);
	}
	
	if (cntNeg % 2 && n % 2 == 0) 
	{
		ans += maxNeg * 2;
		int minVal = 12345;
		for (int i = 0; i < n * 2 - 1; i++) minVal = min(minVal, abs(a[i]));
		if (minVal < -maxNeg) ans -= (maxNeg + minVal) * 2;
	}
	cout << ans << endl;
}