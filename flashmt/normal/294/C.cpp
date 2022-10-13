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

long long fact[1111];

long long power(long long x, int y)
{
	if (!y) return 1;
	long long res = power(x, y / 2);
	res *= res;
	res %= BASE;
	if (y % 2) res = res * x % BASE;
	return res;
}

int main()
{
	int m, n, d[1111] = {0}, x;
	vector <int> a;
	
	cin >> n >> m;
	while (m--) cin >> x, d[x] = 1;
	for (int i = 0; i <= 1000; i++) fact[i] = i ? fact[i - 1] * i % BASE : 1;
	
	int cur = 0;
	for (int i = 1; i <= n; i++)
		if (!d[i]) cur++;
		else
			if (cur) a.push_back(cur), cur = 0;
	if (cur) a.push_back(cur);
	
	
	int sum = 0;
	long long ans = 1;
	for (int i = 0; i < int(a.size()); i++)
	{
		sum += a[i];
		ans = ans * power(fact[a[i]], BASE - 2) % BASE;
		if (!i && !d[1]) continue;
		if (i == int(a.size()) - 1 && !d[n]) continue;
		ans = ans * power(2, a[i] - 1) % BASE;
	}
	ans = ans * fact[sum] % BASE;
	cout << ans << endl;
}