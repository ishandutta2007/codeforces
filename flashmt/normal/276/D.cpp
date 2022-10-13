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

int can(int x, int y, int xx, int yy, int equalL, int equalR)
{
	if (equalL && equalR) return min(xx, yy) >= x && max(xx, yy) <= y;
	if (equalL) return xx >= x;
	if (equalR) return yy <= y;
	return 1;
}

int main()
{
	long long L, R, ans = 0;
	int equalL = 1, equalR = 1;
	
	cin >> L >> R;
	for (int i = 60; i >= 0; i--)
	{
		if (1LL << i > R) continue;
		int x = L >> i & 1, y = R >> i & 1;
		
		if (can(x, y, 1, 0, equalL, equalR))
		{
			ans |= 1LL << i;
			if (!x) equalL = 0;
			if (y) equalR = 0;
		}
		else
			if (can(x, y, 0, 1, equalL, equalR))
				ans |= 1LL << i;
	}
	
	cout << ans << endl;
}