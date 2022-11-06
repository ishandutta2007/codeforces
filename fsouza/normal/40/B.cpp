#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n, m, x;

	scanf(" %d %d %d", &n, &m, &x);

	map <int, int> ret;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if ((y&1) == (x&1)) {
				int d = min(min(y, x), min(n-1-y, m-1-x));
				ret[d] ++;
			}
		}

	printf("%d\n", ret[x-1]);

	return 0;
}