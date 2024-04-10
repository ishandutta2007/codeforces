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

int ok(int n)
{
	int d[10] = {0};
	while (n)
		if (d[n % 10]) return 0;
		else d[n % 10] = 1, n /= 10;
	return 1;
}

int main()
{
	int n;
	cin >> n;
	while (++n)
	{
		if (ok(n)) 
		{
			cout << n << endl;
			return 0;
		}
	}
}