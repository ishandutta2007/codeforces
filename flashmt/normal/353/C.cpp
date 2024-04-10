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
	int n, a[100100], leftSum[100100] = {0};
	string s;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> s;
	
	leftSum[0] = a[0];
	for (int i = 1; i < n; i++) leftSum[i] = leftSum[i - 1] + a[i];
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '1') ans += a[i];
		
	for (int i = n - 1, rightSum = 0; i >= 0; i--)
		if (s[i] == '1')
		{
			if (i) ans = max(ans, rightSum + leftSum[i - 1]);
			rightSum += a[i];
		}
		
	cout << ans << endl;
}