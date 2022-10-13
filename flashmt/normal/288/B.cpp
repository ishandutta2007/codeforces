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
const int BASE = int(1e9) + 7;

int n, k, p[10], d[10];
long long ans;

void att(int i)
{
	if (i == k)
	{
		for (int j = 0; j < k; j++) d[j] = 0;
		for (int j = 1; j < k; j++)
		{
			int x = j;
			while (d[x] != j && x) d[x] = j, x = p[x];
			if (x) return;
		}
		ans++;
		return;
	}
	for (int j = 0; j < k; j++)
		if (!i || i != j)
		{
			p[i] = j;
			att(i + 1);
		}
}

int main()
{
	cin >> n >> k;
	att(0);
	for (int i = 1; i <= n - k; i++) ans = ans * (n - k) % BASE;
	cout << ans << endl;
}