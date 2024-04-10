#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

struct point {
	int x, y, id;
};
 
bool cmp_x(const point & a, const point & b) 
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
bool cmp_y(const point & a, const point & b) 
{
	return a.y < b.y;
}

point a[100100];
long long ans;
 
void updateAns(const point & a, const point & b) 
{
	long long dist = 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
	ans = min(ans, dist);
}
 
void rec(int l, int r) 
{
	if (r - l <= 3) 
	{
		for (int i = l; i <= r; i++)
			for (int j = i + 1; j <= r; j++)
				updateAns(a[i], a[j]);
		sort (a + l, a + r + 1, &cmp_y);
		return;
	}
 
	int m = (l + r) >> 1;
	int midx = a[m].x;
	rec(l, m);  
	rec(m + 1, r);
	
	static point t[100100];
	merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, &cmp_y);
	copy(t, t + r - l + 1, a + l);
 
	int tsz = 0;
	for (int i = l; i <= r; i++)
		if (1LL * (a[i].x - midx) * (a[i].x - midx) < ans) 
		{
			for (int j = tsz - 1; j >= 0 && 1LL * (a[i].y - t[j].y) * (a[i].y - t[j].y) < ans; j--)
				updateAns(a[i], t[j]);
			t[tsz++] = a[i];
		}
}

int n;

int main()
{
	ios::sync_with_stdio(0);
	int x, s = 0;
	
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> x;
		s += x;
		a[i - 1].x = i;
		a[i - 1].y = s;
	}
	
	sort(a, a + n, &cmp_x);
	ans = oo;
	rec(0, n - 1);
	
	cout << ans << endl;
}