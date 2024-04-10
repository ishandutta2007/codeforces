#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int oo = 1000000111, DELTA = 1000000;

int n, Q, m, q[100100], W;
long long ans[100100];
vector <int> X;
vector < pair<int,int> > b, c;

struct wall
{
	int l, r, t;
	wall() {}
	wall(int _l, int _r, int _t)
	{
		l = _l; r = _r; t = _t;
	}
} a[100100];

wall w[500500];

int main()
{
	//freopen("d.in","r",stdin);
	cin >> Q >> n;
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
	a[n + 1].l = 0; a[n + 1].r = oo; a[n + 1].t = oo * 2;
	
	for (int i = 1; i <= n + 1; i++)
	{
		b.push_back(make_pair(a[i].l, i));
		b.push_back(make_pair(a[i].r, -i));
	}
	
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", q + i);
		c.push_back(make_pair(q[i], i + DELTA));
	}
	
	sort(b.begin(), b.end());
	priority_queue < pair<int,int> > q;
	for (int i = 0; i < int(b.size()); )
	{
		int j = i, y = b[i].first;
		if (y == oo) break;
		
		while (j < int(b.size()) && b[j].first == y)
		{
			if (b[j].second > 0) 
			{
				int u = b[j].second;
				q.push(make_pair(-a[u].t, u));
			}
			j++;
		}
		
		int T = oo * 2;		
		while (1)
		{
			pair <int,int> u = q.top();
			int v = u.second;
			if (a[v].r <= y) q.pop();
			else 
			{
				T = a[v].t;
				break;
			}
		}
		
		int yy = b[j].first;
		w[++W] = wall(y, yy, T);
		
		i = j;
	}
	
	for (int i = 1; i <= W; i++)
	{
		c.push_back(make_pair(w[i].t - w[i].l, -i));
		c.push_back(make_pair(w[i].t - w[i].r, i));
	}
	
	sort(c.begin(), c.end());
	long long cnt = 0, num = 0;
	for (int i = 0; i < int(c.size()); i++)
	{
		int y = c[i].second;
		if (y >= DELTA) ans[y - DELTA] += cnt;
		else
			if (y > 0) num++;
			else num--;
			
		if (i + 1 < int(c.size()))
			cnt += num * (c[i + 1].first - c[i].first);
	}
	
	for (int i = 0; i < Q; i++) cout << ans[i] << endl;
}