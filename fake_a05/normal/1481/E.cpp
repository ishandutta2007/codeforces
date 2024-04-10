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

const int maxN = 5e5 + 5;

int N, c[maxN], cnt[maxN], mx, dp[maxN];
int l[maxN], r[maxN];
int ans;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N; 
	loop(i, 1, N)
	{
		l[i] = N + 1; 
		r[i] = 0;
	}
	loop(i, 1, N)
	{
		cin >> c[i];
		cnt[c[i]]++;
		l[c[i]] = min(l[c[i]], i);
		r[c[i]] = max(r[c[i]], i);
	}
	loop(i, 1, N)
	{
		dp[i] = dp[i - 1];
		if(i == r[c[i]]) dp[i] = max(dp[i], cnt[c[i]] + dp[l[c[i]] - 1]);
//		cout << dp[i] << endl;
	}
	loop(i, 1, N) cnt[i] = 0;
	rloop(i, N + 1, 1)
	{
		if(i <= N) 
		{
			cnt[c[i]]++;
			mx = max(mx, cnt[c[i]]);
		}
		ans = max(ans, dp[i - 1] + mx);
	}
	cout << N - ans;
}