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

long long tree[1000100];
int last[1000100], n, a[100100];

void add(int x, long long v)
{
	for (int i = x; i <= 1000000; i += i & - i)
		tree[i] += v, tree[i] %= BASE;
}
	
long long get(int x)
{
	long long res = 0;
	for (int i = x; i; i -= i & -i) res += tree[i], res %= BASE;
	return res;
}	

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", a + i), last[a[i]] = i;
	
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		long long u = get(a[i]), t = u - get(a[i] - 1);
		u = (u * a[i] + a[i]) % BASE;
		if (last[a[i]] == i) ans += u, ans %= BASE;
		add(a[i], (u + BASE - t) % BASE);
	}
	
	cout << ans << endl;
}