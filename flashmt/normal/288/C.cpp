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

int p[1000100];

void solve(int n)
{
	if (!n) return;
	if (n == 1)
	{
		p[0] = 1; return;
	}
	
	int p2 = 1;
	while (p2 * 2 <= n) p2 *= 2;
	int j = p2 - 1;
	for (int i = p2; i <= n; i++, j--) p[i] = j, p[j] = i;
	solve(j);
}

int main()
{
	int n;
	cin >> n;
	cout << 1LL * n * (n + 1) << endl;
	solve(n);
	for (int i = 0; i <= n; i++) printf("%d ", p[i]);
	puts("");
}