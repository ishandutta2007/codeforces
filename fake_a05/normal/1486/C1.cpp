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
	if(l == r) 
	{
		ans[{l, r}] = l - 1;
		return;
	}
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
		int l = 1, r = N;
		while(l < r)
		{
			int m = (l + r) / 2;
			ask(l, r);
			int t = ans[{l, r}];
			if(t > m) ask(m + 1, r);
			else ask(l, m);
			int tl = (t > m)? ans[{m + 1, r}]: ans[{l, m}];
			if((t == tl and t > m) or (t != tl and t <= m)) l = m +1;
			else r = m;
		}
		a(l);
//	}
}