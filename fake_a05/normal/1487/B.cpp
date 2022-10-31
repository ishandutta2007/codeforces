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
	int tc;
	cin >> tc;
	while(tc--)
	{
		int N, K;
		cin >> N >> K;
		int t = N / 2, inc = K - 1;
		if(N & 1)
		{
			cout << (inc / t * (t + 1) + inc % t) % N + 1 << endl;
		}
		else cout << (K - 1) % N + 1 << endl;
	}
}