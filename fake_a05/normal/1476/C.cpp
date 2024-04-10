#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb emplace_back
#define all(x) begin(x), end(x)

#define rand rng
#define endl '\n'
#define sp ' '

#define int long long
const int maxN = 1e5 + 5;
int tc, N;
int c[maxN], a[maxN], b[maxN];
int dp[maxN];
int ans;
signed main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while(tc--)
	{
		cin >> N;
		loop(i, 1, N) dp[i] = 0;
		ans = 0;
		loop(i, 1, N) cin >> c[i];
		loop(i, 1, N) cin >> a[i];
		loop(i, 1, N) cin >> b[i];
		loop(i, 2, N)
		{
			if(a[i] == b[i]) dp[i] = c[i] - 1 + 2;
			else if(a[i] < b[i])
			{
				dp[i] = max(c[i] - 1 + 2 + b[i] - a[i], c[i] - 1 + 2 + dp[i - 1] - (b[i] - a[i]));
			}
			else
			{
				dp[i] = max(c[i] - 1 + 2 + a[i] - b[i], c[i] - 1 + 2 + dp[i - 1] - (a[i] - b[i]));
			}
		}
		loop(i, 1, N) ans = max(ans, dp[i]);
		cout << ans << endl;
	}
}