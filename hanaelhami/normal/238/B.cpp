#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 1e5 + 20;

pair<int , int> a[maxn];

int h , n;

bool ans[maxn] , tmp[maxn];

int z[maxn];

vector<ll> x[2];

ll res = 1e17;

void solve()
{
	x[0].clear();
	x[1].clear();
	for(int i = 0; i < n; i++)
		x[tmp[i]].pb(a[i].first);
	ll mx = 0;
	if(!x[0].empty() && !x[1].empty())
		mx = max(mx , x[0].back() + x[1].back() + h);
	for(int i = 0; i < 2; i++)
		if(1 < (int)x[i].size())
		{
			ll k = x[i].back();
			x[i].pop_back();
			mx = max(mx , k + x[i].back());
			x[i].pb(k);
		}
	ll mn = 1e16;
	for(int i = 0; i < 2; i++)
	{
		reverse(x[i].begin() , x[i].end());
		if(1 < (int)x[i].size())
		{
			ll k = x[i].back();
			x[i].pop_back();
			mn = min(mn , k + x[i].back());
			x[i].pb(k);
		}
	}
	if(!x[0].empty() && !x[1].empty())
		mn = min(mn , x[0].back() + x[1].back() + h);
	if(mx - mn < res)
	{
		res = mx - mn;
		for(int i = 0; i < n; i++)
			ans[i] = tmp[i];
	}
}

int main()
{
	srand(time(NULL));
	cin >> n >> h;
	for(int i = 0; i < n; i++)
		cin >> a[i].first , a[i].second = i;
	sort(a , a + n);
	solve();
	for(int _ = 0; _ < 50; _++)
	{
		for(int i = 0; i < n; i++)
		{
			int k = rand() % 2;
			if(k)
				tmp[i] = 1;
			else
				tmp[i] = 0;
		}
		solve();
	}
	if(n >= 8)
	{
		fill(tmp , tmp + maxn , 0);
		for(int mask = 0; mask < (1 << 4); mask++)
			for(int mask2 = 0; mask2 < (1 << 4); mask2++)
			{
				for(int i = 0; i < 4; i++)
					tmp[i] = bit(mask , i);
				for(int i = 0; i < 4; i++)
					tmp[n - i] = bit(mask2 , i);
				solve();
			}
	}
	cout << res << endl;
	for(int i = 0; i < n; i++)
		z[a[i].second] = ans[i];
	for(int i = 0; i < n; i++)
		cout << z[i] + 1 << " ";
	cout << endl;
}