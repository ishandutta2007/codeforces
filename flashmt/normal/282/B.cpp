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
	int n, dif = 0, x, y;
	cin >> n;
	while (n--)
	{
		scanf("%d%d", &x, &y);
		if (abs(dif + x) <= abs(dif - y)) dif += x, printf("A");
		else dif -= y, printf("G");
	}
}