#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define eb emplace_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 2e5 + 5, inf = LLONG_MAX / 1000ll;

multiset<int> x[4];
int dp[4][maxN];
int N[4];
vi av[4][maxN];
int c[4][maxN];
void del(multiset<int> &m, int v)
{
	m.erase(m.find(v));
}
void ins(multiset<int> &m, int v)
{
	m.insert(v);
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	loop(i, 0, 3)
	{
		cin >> N[i];
	}
	loop(i, 0, 3)
	{
		loop(j, 1, N[i])
		{
			cin >> c[i][j];
			dp[i][j] = inf;
		}
	}
	loop(i, 1, 3)
	{
		int m;
		cin >> m;
		while(m--)
		{
			int k, h;
			cin >> k >> h;
			av[i][h].eb(k);
		}
	}
	loop(i, 0, 3)
	{
		loop(j, 1, N[i])
		{
			if(!i) dp[i][j] = c[i][j];
			else
			{
				for(int k: av[i][j])
				{
					del(x[i - 1], dp[i - 1][k]);
				}
				int t;
				if(x[i - 1].empty())t = inf;
				else t = * x[i - 1].begin();
				dp[i][j] = t + c[i][j];
				for(int k: av[i][j])
				{
					ins(x[i - 1], dp[i - 1][k]);
				}  
			}
			ins(x[i], dp[i][j]);
		}
	}
	int ans = x[3].empty()? inf: * x[3].begin();
	cout << (ans >= inf? -1: ans);
}