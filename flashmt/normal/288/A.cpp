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
	if (n < k) puts("-1");
	else
		if (k == 1)
		{
			if (n > 1) puts("-1");
			else puts("a");
		}
		else
		{
			for (int i = 0; i < n - k + 2; i++) printf("%c", char('a' + i % 2));
			for (int i = 2; i < k; i++) printf("%c", char('a' + i));
			puts("");
		}
}