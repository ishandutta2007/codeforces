// Codeforces Beta Round #15
// Problem D -- Map
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

#define N 1000

using namespace std;

int n, m, a, b, h[N][N], t[N][N], l[N][N], q[N];
bool v[N][N];
long long s[N][N];
pair<long long, pair<int, int> > o[N * N], aw[N * N];

long long get_s(int i, int j)
{
	if(i < 0 || j < 0)
		return 0;
	return s[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> a >> b;
	for(int i = 0; i != n; ++ i)
		for(int j = 0; j != m; ++ j)
			cin >> h[i][j];
	for(int i = 0; i != n; ++ i)
	{
		int hd = 0, tl = 0;
		for(int j = 0; j != m; ++ j)
		{
			while(hd != tl && h[i][q[tl - 1]] >= h[i][j])
				tl --;
			q[tl ++] = j;
			while(hd != tl && j - q[hd] >= b)
				hd ++;
			t[i][j] = h[i][q[hd]];
		}
	}
	for(int j = 0; j != m; ++ j)
	{
		int hd = 0, tl = 0;
		for(int i = 0; i != n; ++ i)
		{
			while(hd != tl && t[q[tl - 1]][j] >= t[i][j])
				tl --;
			q[tl ++] = i;
			while(hd != tl && i - q[hd] >= a)
				hd ++;
			l[i][j] = t[q[hd]][j];
		}
	}
	memset(s, 0, sizeof(s));
	for(int i = 0; i != n; ++ i)
		for(int j = 0; j != m; ++ j)
			s[i][j] = get_s(i, j - 1) + get_s(i - 1, j) - get_s(i - 1, j - 1) + h[i][j];
	int sz = 0;
	for(int i = a - 1; i != n; ++ i)
		for(int j = b - 1; j != m; ++ j)
		{
			long long temp = get_s(i, j) - get_s(i - a, j) - get_s(i, j - b) + get_s(i - a, j - b);
			temp -= (long long)(l[i][j]) * a * b;
			o[sz ++] = make_pair(temp, make_pair(i, j));
		}
	sort(o, o + sz);
	memset(v, 0, sizeof(v));
	int ct = 0;
	for(int i = 0; i != sz; ++ i)
	{
		int x = o[i].second.first, y = o[i].second.second;
		if(v[x][y] || v[x - a + 1][y] || v[x][y - b + 1] || v[x - a + 1][y - b + 1])
			continue;
		aw[ct ++] = o[i];
		for(int j = x - a + 1; j <= x; ++ j)
			for(int k = y - b + 1; k <= y; ++ k)
				v[j][k] = true;
	}
	cout << ct << "\n";
	for(int i = 0; i != ct; ++ i)
	{
		int x = aw[i].second.first, y = aw[i].second.second;
		cout << x - a + 2 << " " << y - b + 2 << " " << aw[i].first << "\n";
	}
	return 0;
}