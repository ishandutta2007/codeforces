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

char a[2000100], b[2000100];
int d[2][2];

int main()
{
	int n;
	cin >> n;
	scanf("%s%s", a, b);
	
	for (int i = 0; i < n * 2; i++) d[a[i] - '0'][b[i] - '0']++;

	int y = d[1][1] / 2, x = d[1][1] - y;
	if (y < x)
	{
		if (d[0][1]) y++, d[0][1]--;
		else
			if (d[1][0]) d[1][0]--;
	}
	
	int u = min(d[0][1], d[1][0]);
	d[0][1] -= u; d[1][0] -= u;
	
	if (d[1][0] > 0) x += (d[1][0] + 1) / 2;
	if (d[0][1] > 0) y += d[0][1] / 2;
	
	if (x == y) puts("Draw");
	else puts(x > y ? "First" : "Second");
}