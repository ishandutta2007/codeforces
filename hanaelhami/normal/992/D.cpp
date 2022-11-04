#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 2e5 + 20;
const ll inf = 8e18;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	vector<pair<int , int> > shit;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if(shit.empty() || x != 1)
			shit.pb(make_pair(x , 0));
		else
			shit.back().second++;
	}

	ll res = 0;
	if(k == 1)
		for(auto x : shit)
			res += x.second;

	n = shit.size();
	for(int l = 0; l < n; l++)
	{
		ll mul = 1 , sum = 0;
		for(int r = l; r < n; r++)
		{
			if(shit[r].first > inf / mul)
				break;
			mul *= shit[r].first;
			sum += shit[r].first;

			if(mul % k == 0 && mul / k >= sum)
			{
				int a = 0 , b = shit[r].second;
				if(l > 0)
					a = shit[l - 1].second;

				ll remain = mul / k - sum;

				if(a + b >= remain)
				{
					int x = min(a , remain);
					int L = remain - x;
					int R = min(L + x , b);
					res += R - L + 1;
				}
			}

			sum += shit[r].second;
		}
	}

	cout << res << endl;

}