#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

long long n,m,k;

int main()
{
	cin >> n >> m >> k;
	if (n * m * 2 % k != 0)
		puts("NO");
	else
	{
		bool flag = 0;
		if (k % 2 == 0)
		{
			k /= 2;
			flag = 1;
		}
		long long p = n,q = m;
		long long g = __gcd(p,k);
		p /= g;
		k /= g;
		q /= k;
		if (!flag)
		{
			if (p * 2 <= n)
				p <<= 1;
			else
				q <<= 1;
		}
		puts("YES");
		cout << 0 << ' ' << 0 << endl;
		cout << 0 << ' ' << q << endl;
		cout << p << ' ' << 0 << endl;
	}
	return 0;
}