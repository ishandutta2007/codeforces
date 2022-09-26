#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

namespace Input
{
	const int BUF = 65536;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;

	inline char inputchar()
	{
		if (head == tail)
			*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
		return *head++;
	}

	inline void read(int &ret)
	{
		char ch = inputchar();
		while (ch < '0' || ch > '9')
			ch = inputchar();
		for (ret = 0; ch >= '0' && ch <= '9'; ch = inputchar())
			ret = ret * 10 + ch - '0';
	}
}
using Input::read;

const int MAXN = 400005;

int a[MAXN], last[MAXN], pre[MAXN], next[MAXN];

int n, k, res = 0;

set<int> myset;

int main()
{
	//freopen("1.in", "r", stdin);
	memset(last, 0, sizeof(last));
	memset(next, 0, sizeof(next));
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		pre[i] = last[a[i]], last[a[i]] = i;
	for (int i = 1; i <= n; i++)
		if (pre[i] != 0)
			next[pre[i]] = i;
	for (int i = 1; i <= n; i++)
	{
		if (myset.find(i) != myset.end())
		{
			myset.erase(i);
			if (next[i] != 0)
				myset.insert(next[i]);
			continue;
		}
		res++;
		if (myset.size() == k)
			myset.erase(*myset.rbegin());
		if (next[i] != 0)
			myset.insert(next[i]);
	}
	cout << res << endl;
	return 0;
}