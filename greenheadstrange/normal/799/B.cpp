#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 200005 
using namespace std;
struct th
{
	int a, b, p;
	bool operator < (const th&a)const
	{
		return p > a.p;
	}
}x[maxn];
struct heap
{
	priority_queue <th> ins, del;
	void d(th a){del.push(a);}
	void i(th a){ins.push(a);}
	th q()
	{
		while(!del.empty() && del.top().p == ins.top().p)
			del.pop(), ins.pop();
		if(ins.empty()) 
		{
			th new1;
			new1.a = new1.b = new1.p = -1;
			return new1;
		}
		else return ins.top();
	}
}h[4];
int main()
{
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i].p);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i].a);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i].b);
	for(int i = 1; i <= n; i++)
		h[x[i].a].i(x[i]), h[x[i].b].i(x[i]);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int c;
		scanf("%d", &c);
		th ans = h[c].q();
		printf("%d ", ans.p);
		if(ans.p != -1) h[ans.a].d(ans), h[ans.b].d(ans);
	}
	return 0;
}