#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

long long ans[5000005];

int main()
{
	long long p,k,ANS = -2;
	cin >> p >> k;
	for (int i = 0;i <= 5000000;i++)
	{
		if (p >= 0 && p < k)
		{
			ans[i] = p;
			ANS = i;
			break;
		}
		long long q = -p / k;
		ans[i] = p + q * k;
		if (ans[i] < 0)
			ans[i] += k,q++;
		p = q;
	}
	cout << ANS + 1 << endl;
	for (int i = 0;i <= ANS;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}