#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define eb push_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
//#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 5e5 + 5, maxW = 3005, mod = 998244353, inf = LLONG_MAX / 1000ll;

map<ii, int> ans;

void ask(int l, int r)
{
	if(ans.count({l, r})) return;
	cout << "? " << l << sp << r << endl;
	cin >> ans[{l, r}];
}

void a(int p)
{
	cout << "! " << p << endl;
}

signed main()
{
//	freopen("ball.inp", "r", stdin);
//	freopen("ball.out", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int tc;
//	cin >> tc;
//	while(tc--)
//	{
		int N;
		cin >> N;
		ask(1, N);
		int ovr = ans[{1, N}];
		bool tr = 0;
		if(ovr < N)
		{
			ask(ovr, N);
			int t = ans[{ovr, N}];
			if(t == ovr) tr = 1;
			else tr = 0;
		}
		if(tr)
		{
			int l = ovr + 1, r = N;
			while(l < r)
			{
				int m = (l + r) / 2;
				ask(ovr, m);
				if(ans[{ovr, m}] == ovr) r = m;
				else l = m + 1;
			}
			a(l);
		}
		else
		{
			int l = 1, r = ovr - 1;
			while(l < r)
			{
				int m = (l + r + 1) / 2;
				ask(m, ovr);
				if(ans[{m, ovr}] == ovr) l = m;
				else r = m - 1;
			}
			a(l);
		}
//	}
}