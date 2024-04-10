#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, timeIn[100100], timeOut[100100], step, ans[100100];
int f[600500], cnt[600500];
vector <int> a[100100], query[100100];

void visit(int x, int par)
{
	timeIn[x] = ++step;
	for (int i = 0; i < int(a[x].size()); i++)
		if (a[x][i] != par) visit(a[x][i], x);
	timeOut[x] = step;
}

void add(int nd, int l, int r, int x, int y, int val)
{
	if (l == x && r == y)
	{
		f[nd] += val;
		if (f[nd]) cnt[nd] = r - l + 1;
		else cnt[nd] = cnt[nd * 2] + cnt[nd * 2 + 1];
	}
	else
	{
		int m = (l + r) / 2;
		
		if (x <= m) add(nd * 2, l, m, x, min(y, m), val);
		if (m < y) add(nd * 2 + 1, m + 1, r, max(x, m + 1), y, val);
		
		if (f[nd]) cnt[nd] = r - l + 1;
		else cnt[nd] = cnt[nd * 2] + cnt[nd * 2 + 1];
	}
}

void calc(int x, int par)
{
	for (int i = 0; i < int(query[x].size()); i++)
	{
		int y = query[x][i];
		add(1, 1, n, timeIn[y], timeOut[y], 1);
	}
	
	ans[x] = cnt[1];
	
	for (int i = 0; i < int(a[x].size()); i++)
		if (a[x][i] != par) calc(a[x][i], x);
	
	for (int i = 0; i < int(query[x].size()); i++)
	{
		int y = query[x][i];
		add(1, 1, n, timeIn[y], timeOut[y], -1);
	}
}

int main()
{
	int Q, x, y;
	cin >> n >> Q;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	visit(1, 0);
	
	while (Q--)
	{
		cin >> x >> y;
		if (timeIn[x] > timeIn[y]) swap(x, y);
		
		if (timeOut[x] >= timeOut[y]) query[x].push_back(x); 
		else
		{
			query[x].push_back(y); query[x].push_back(x);
			query[y].push_back(x); query[y].push_back(y);
		}
	}
	
	calc(1, 0);
	
	for (int i = 1; i <= n; i++) cout << max(0, ans[i] - 1) << ' ';
}