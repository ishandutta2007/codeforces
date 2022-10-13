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
const int BASE = int(1e9);

long long f[111], a[111];
int n;

int main()
{
	int m, x, y, t, d;
	
	f[0] = f[1] = 1;
	for (int i = 2; i <= 100; i++) f[i] = (f[i - 1] + f[i - 2]) % BASE;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	while (m--)
	{
		cin >> t >> x >> y;
		if (t == 1) a[x] = y;
		if (t == 2)
		{
			long long ans = 0;
			for (int i = x; i <= y; i++) ans = (ans + f[i - x] * a[i]) % BASE;
			cout << ans << endl;
		}
		if (t == 3)
		{
			cin >> d;
			for (int i = x; i <= y; i++) a[i] = (a[i] + d) % BASE;
		}
	}
}