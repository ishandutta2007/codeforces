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
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 5e5 + 5, maxW = 3005, mod = 998244353, inf = LLONG_MAX / 1000ll;

int N, M; 
int st[maxN], arr[maxN], sum0, sum1, dp[2][maxW][maxW];
int bp(int i, int j)
{
	int r = 1;
	while(j)
	{
		if(j & 1) r = r * i % mod;
		i = i * i % mod;
		j >>= 1; 
	}
	return r;
}
void getdp(int s, int w, int l)
{
	if(w + l == M) dp[s][w][l] = 1;
	if(dp[s][w][l] != -1) return;
	dp[s][w][l] = 0;
	if(!s) 
	{
		if(sum0 == l) return;
		int ll = sum0 - l - 1, wl = sum1 + w, tot = ll + wl + 1;
		int c = bp(tot, mod - 2);
		if(ll) // lose
		{
			getdp(s, w, l + 1);
			dp[s][w][l] = (dp[s][w][l] + ll * c % mod * dp[s][w][l + 1]) % mod;
		}
		// win
		if(wl)
		{
			getdp(s, w + 1, l);
			dp[s][w][l] = (dp[s][w][l] + wl * c % mod * dp[s][w + 1][l]) % mod;
		}
		// self // nothing happens, dead already
	}
	else
	{
		int ll = sum0 - l, wl = sum1 + w - 1, tot = ll + wl + 1;
		int c = bp(tot, mod - 2);
		if(ll) // lose
		{
			getdp(s, w, l + 1);
			dp[s][w][l] = (dp[s][w][l] + ll * c % mod * dp[s][w][l + 1]) % mod;
		}
		if(wl) // win
		{
			getdp(s, w + 1, l);
			dp[s][w][l] = (dp[s][w][l] + wl * c % mod * dp[s][w + 1][l]) % mod;
		}
		// self
		getdp(s, w + 1, l);
		dp[s][w][l] = (dp[s][w][l] + c * 2 % mod * dp[s][w + 1][l]) % mod;
	}
}
signed main()
{
//	freopen("ball.inp", "r", stdin);
//	freopen("ball.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--)
	{
		int N; cin >> N;
		vi h, w;
		h = w = vi(N, 0);
		loop(i, 0, N - 1) cin >> h[i] >> w[i];
		sort(all(h));
		sort(all(w));
		int m = N / 2;
		if(N & 1) cout << 1 << endl;
		else cout << 1ll * (h[m] - h[m - 1] + 1) * (w[m] - w[m - 1] + 1) << endl;
	}
}