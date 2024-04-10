#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

long long a[14];
long long b[14];
long long ans;

int main()
{
	for (int i = 0;i < 14;i++)
		cin >> a[i];
	for (int i = 0;i < 14;i++)
	{
		memcpy(b,a,sizeof(b));
		long long t = b[i];
		if (!t)
			continue;
		b[i] = 0;
		for (int j = 0;j < 14;j++)
		{
			b[j] += t / 14;
			if ((j - i + 13) % 14 < t % 14)
				b[j]++;
		}
		long long cur = 0;
		for (int j = 0;j < 14;j++)
			if (!(b[j] & 1))
				cur += b[j];
		ans = max(ans,cur);
	}
	cout << ans << endl;
	return 0;
}