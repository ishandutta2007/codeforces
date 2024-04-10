#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define maxn 200005
using namespace std;
int n, c[maxn], m;
vector<int> t[maxn];
struct node
{
	int a[15], pos, data;
	bool friend operator < (node aa, node bb)
	{
		if(aa.data != bb.data) return aa.data < bb.data;
		for (int i = 1; i <= n; i++)
		{
			if(aa.a[i] != bb.a[i]) return aa.a[i] > bb.a[i];
		}
	}
	bool friend operator == (node aa, node bb)
	{
		for (int i = 1; i <= n; i++) 
		{
			if(aa.a[i] != bb.a[i]) return 0;
		}
		return 1;
	}
};
priority_queue<node> q;
node bn[maxn];
inline bool cmp(node aa, node bb)
{
	return !(aa < bb);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		t[i].push_back(0);
		for (int j = 1; j <= c[i]; j++)
		{
			int x;
			scanf("%d", &x);
			t[i].push_back(x);
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &bn[i].a[j]);
			bn[i].data += t[j][bn[i].a[j]];
		}
	}
	sort(bn + 1, bn + m + 1, cmp);
	node tmp;
	for (int i = 1; i <= n; i++) tmp.a[i] = c[i];
	for (int i = 1; i <= n; i++) tmp.data += t[i][c[i]];
	tmp.pos = 1;
	q.push(tmp);
	for (int i = 1; ; i++)
	{
		tmp = q.top();
		q.pop();
		if(i > m || !(tmp == bn[i]))
		{
			for (int j = 1; j <= n; j++) printf("%d ", tmp.a[j]);
			return 0;
		}
		for (int j = tmp.pos; j <= n; j++)
		{
			if(tmp.a[j] == 1) continue;
			node nxt = tmp;
			nxt.pos = j;
			nxt.a[j]--;
			nxt.data += t[j][nxt.a[j]] - t[j][nxt.a[j] + 1];
			q.push(nxt);
		}
	}
	return 0;
}