#include <bits/stdc++.h>
using namespace std;
const int MAXC = 100100;

struct point
{
	int x, y, id;
	point(int _x, int _y, int _id): x(_x), y(_y), id(_id) {}
};

bool cmpHor(point u, point v)
{
	return u.y < v.y || (u.y == v.y && u.x < v.x);
}

bool cmpVer(point u, point v)
{
	return u.x < v.x || (u.x == v.x && u.y < v.y);
}

bool cmpDia(point u, point v)
{
	return u.x - u.y < v.x - v.y || (u.x - u.y == v.x - v.y && u.x < v.x);
}

int cnt[100100], direction[100100];
vector <point> a;
unordered_set <int> row[100100];

int main()
{
	ios::sync_with_stdio(0);
	
	int x, y, n;
	set < pair<int,int> > s;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		row[x].insert(y);
		a.push_back(point(x, y, i));
	}
	
	sort(a.begin(), a.end(), cmpHor);		
	for (int i = n - 1, cur = 0; i >= 0; i--)
	{
		if (i + 1 < n && a[i + 1].y == a[i].y) cur++;
		else cur = 0;
		cnt[a[i].id] = cur;
		direction[a[i].id] = 0;
	}
	
	sort(a.begin(), a.end(), cmpVer);		
	for (int i = n - 1, cur = 0; i >= 0; i--)
	{
		if (i + 1 < n && a[i + 1].x == a[i].x) cur++;
		else cur = 0;
		if (cur < cnt[a[i].id]) cnt[a[i].id] = cur, direction[a[i].id]  = 1;
	}
	
	sort(a.begin(), a.end(), cmpDia);		
	for (int i = n - 1, cur = 0; i >= 0; i--)
	{
		if (i + 1 < n && a[i + 1].x - a[i + 1].y == a[i].x - a[i].y) cur++;
		else cur = 0;
		if (cur < cnt[a[i].id]) cnt[a[i].id] = cur, direction[a[i].id] = 2;
	}
	
	long long ans = 0;
	
	for (int i = 0; i < n; i++)
		if (direction[a[i].id] == 2)
			for (int j = i + 1; j < n && a[j].x - a[j].y == a[i].x - a[i].y; j++)
				if (row[a[i].x].count(a[j].y) && row[a[j].x].count(a[i].y))
					ans++;
					
	sort(a.begin(), a.end(), cmpVer);
	for (int i = 0; i < n; i++)
		if (direction[a[i].id] == 1)
			for (int j = i + 1; j < n && a[i].x == a[j].x; j++)
				if (row[a[i].x + a[j].y - a[i].y].count(a[i].y) && row[a[i].x + a[j].y - a[i].y].count(a[j].y))
					ans++;
					
	sort(a.begin(), a.end(), cmpHor);
	for (int i = 0; i < n; i++)
		if (direction[a[i].id] == 0)
			for (int j = i + 1; j < n && a[i].y == a[j].y; j++)
				if (row[a[i].x].count(a[i].y + a[j].x - a[i].x) && row[a[j].x].count(a[i].y + a[j].x - a[i].x))
					ans++;
					
	cout << ans << endl;
}