#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

struct Node
{
	int ch[2];
	int fa;
	int cnt;
}node[9000005];

int n,p,id;
int a[300005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	node[0].fa = -1;
	for (int i = 1;i <= n;i++)
	{
		cin >> p;
		int now = 0;
		for (int i = 29;i >= 0;i--)
		{
			bool bit = ((p >> i) & 1);
			if (!node[now].ch[bit])
				node[node[now].ch[bit] = ++id].fa = now;
			now = node[now].ch[bit];
		}
		for (;now != -1;now = node[now].fa)
			node[now].cnt++;
	}
	for (int i = 1;i <= n;i++)
	{
		int cur = a[i],now = 0,ans = 0;
		for (int i = 29;i >= 0;i--)
		{
			bool bit = ((cur >> i) & 1);
			if (!node[now].ch[bit] || !node[node[now].ch[bit]].cnt)
				ans |= (1 << i),now = node[now].ch[bit ^ 1];
			else
				now = node[now].ch[bit];
		}
		for (;now != -1;now = node[now].fa)
			node[now].cnt--;
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}