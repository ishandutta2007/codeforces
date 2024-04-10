#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

int m, n, a[100100];
long long len;
vector < pair<long long,long long> > ids;
vector <int> start, period;
map <long long,int> mp;

int main()
{
	ios::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	int type, x, c;
	
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> type >> x;
		if (type == 1) 
		{
			if (len < MAXN) a[len++] = x;
			else mp[len++] = x;
		}
		else
		{
			cin >> c;
			int rest = x * c, j;
			for (j = 0; j < rest && len < MAXN; j++)
				a[len++] = a[j % x];
				
			if (j == rest) continue;
			
			rest -= j;
			ids.push_back(make_pair(len, len + rest - 1));
			start.push_back(j % x);
			period.push_back(x);
			len += rest;
		}
	}
	
	cin >> n;
	int i = 0;
	long long id;
	while (n--)
	{
		cin >> id;
		id--;
		if (id < MAXN) cout << a[id] << ' ';
		else if (mp.count(id)) cout << mp[id] << ' ';
		else
		{
			while (ids[i].second < id) i++;
			int dif = (id - ids[i].first) % period[i];
			cout << a[(start[i] + dif) % period[i]] << ' ';
		}
	}
}