#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <set>

using namespace std;

long long a;
long long c[100005];

long long x,y,l,r;

set<long long> cnt;

int main()
{
	cin >> x >> y >> l >> r;
	long long tmpa = 1,tmpb = 1;
	for (int i = 0;;i++)
	{
		for (int j = 0;;j++)
		{
			long long sum = tmpa + tmpb;
			if (sum >= l && sum <= r)
				cnt.insert(sum);
			if ((double)tmpb > (double)(r / y))
			{
				tmpb = 1;
				break;
			}
			tmpb *= y;
		}
		if ((double)tmpa > (double)(r / x))
			break;
		tmpa *= x;
	}
	cnt.insert(l - 1);
	cnt.insert(r + 1);
	long long MAX = 0,id = 0;
	for (set<long long>::const_iterator i = cnt.begin();i != cnt.end();i++)
		c[++id] = *i;
	for (int i = 1;i < id;i++)
		MAX = max(MAX,c[i + 1] - c[i] - 1);
	cout << MAX << endl;
	return 0;
}