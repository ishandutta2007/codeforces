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
	int n, k;
	cin >> n >> k;
	if (k >= n * (n - 1) / 2) puts("no solution");
	else
		for (int i = 0, y = int(1e9); i < n; i++, y -= int(1e5)) cout << i << ' ' << y << endl;
}