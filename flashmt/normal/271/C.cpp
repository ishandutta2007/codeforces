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
	if (3 * k > n) puts("-1");
	else
	{
		for (int i = 0; i < k; i++) printf("%d ", (i + 1) % k + 1);
		for (int i = k; i < n; i++) printf("%d ", i % k + 1);
	}
}