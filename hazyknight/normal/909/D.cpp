#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cctype>

using namespace std;

string s;

int n,ans;

pair<int,int> a[1000005];

void update()
{
	int last = 0;
	for (int i = 1;i <= n;i++)
	{
		if (!a[i].second)
			continue;
		if (a[i].first == a[last].first)
			a[last].second += a[i].second;
		else
			a[++last] = a[i];
	}
	n = last;
}

int search()
{
	if (n == 1)
		return 0;
	int ret = min(a[1].second,a[n].second);
	for (int i = 2;i < n;i++)
		ret = min(ret,(a[i].second + 1) >> 1);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	for (int i = 0;i < n;i++)
		a[i + 1] = make_pair(s[i],1);
	update();
	int cnt = 0;
	while (cnt = search())
	{
		ans += cnt;
		a[1].second -= cnt;
		a[n].second -= cnt;
		for (int i = 2;i < n;i++)
		{
			a[i].second -= (cnt << 1);
			a[i].second = max(a[i].second,0);
		}
		update();
	}
	cout << ans << endl;
	return 0;
}