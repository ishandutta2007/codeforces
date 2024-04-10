#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
	int a, b;
	string s;

	cin >> a >> b >> s;

	int dx = 0, dy = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U') dy ++;
		if (s[i] == 'D') dy --;
		if (s[i] == 'L') dx --;
		if (s[i] == 'R') dx ++;
	}

	int mint;

	if (dx != 0)
		mint = a/dx;
	else if (dy != 0)
		mint = b/dy;
	else
		mint = 0;

	mint = max(mint-101*101, 0);

	int y = mint*dy, x = mint*dx;

	bool ret = false;

	for (int rep = 0; rep < 2*101*101; rep++)
		for (int i = 0; i < s.size(); i++) {
			if (x == a && y == b)
				ret = true;
			if (s[i] == 'U') y ++;
			if (s[i] == 'D') y --;
			if (s[i] == 'L') x --;
			if (s[i] == 'R') x ++;
			if (x == a && y == b)
				ret = true;
		}

	printf(ret ? "Yes\n" : "No\n");

	return 0;
}