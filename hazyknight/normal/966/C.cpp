#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct B
{
	int next;
	long long val;
}b[100005];

int n,id;
int first;

vector<long long> c[65];

int maxbit(long long now)
{
	int ret = 0;
	while (now > 0)
	{
		ret++;
		now >>= 1;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		long long b;
		cin >> b;
		c[maxbit(b)].push_back(b);
	}
	for (int i = 60;i >= 0;i--)
	{
		if (!c[i].size())
			continue;
		int next = first,pre = 0;
		bool flag = 0;
		long long Xor = 0;
		first = id + 1;
		while ((!flag || pre) && c[i].size())
		{
			flag = 1;
			if (Xor < (Xor ^ c[i].back()))
			{
				++id;
				b[id].next = next;
				b[pre].next = id;
				b[id].val = c[i].back();
				c[i].pop_back();
				Xor ^= c[i].back();
			}
			Xor ^= b[next].val;
			pre = next;
			next = b[next].next;
		}
		if (c[i].size())
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (int i = first;i;i = b[i].next)
		cout << b[i].val << ' ';
	cout << endl;
	return 0;
}