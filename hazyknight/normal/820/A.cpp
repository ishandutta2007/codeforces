#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>

using namespace std;

int c,v0,v1,a,l;
int ans;

int main()
{
	cin >> c >> v0 >> v1 >> a >> l;
	while (1)
	{
		ans++;
		if (ans >= 2)
			c += l;
		c -= v0;
		if (c <= 0)
			break;
		v0 = min(v1,v0 + a);
	}
	cout << ans << endl;
	return 0;
}