#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct line
{
	int x, y, id;
	
	line() {}
	line(int _x, int _y, int _id) : x(_x), y(_y), id(_id) {}
	
	bool operator < (line u) const
	{
		return y < u.y;
	}
};

int n, cw[100100], ccw[100100], tree[400400];
line a[100100];
long long ans;

void add(int x)
{
	for (int i = x; i <= n * 4; i += i & -i) tree[i]++;
}

int get(int x)
{
	int res = 0;
	for (int i = x; i; i -= i & -i) res += tree[i];
	return res;
}

int main()
{
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		scanf("%d%d", &x, &y); 
		if (x > y) swap(x, y);
		a[i] = line(x, y, i);
	}	

	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		cw[a[i].id] = get(a[i].y) - get(a[i].x);
		add(a[i].x);
		swap(a[i].y, a[i].x);
	}
	
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		ccw[a[i].id] = get(a[i].y + n * 2) - get(a[i].x);
		add(a[i].x);
		add(a[i].x + n * 2);
	}
	
	for (int i = 0; i < n; i++) 
	{
		ans += 2LL * cw[i] * ccw[i];
		ans += (cw[i] + ccw[i]) * (n - 1LL - cw[i] - ccw[i]);
	}
	
	ans = n * (n - 1LL) * (n - 2) / 6 - ans / 2;
	cout << ans << endl;
}