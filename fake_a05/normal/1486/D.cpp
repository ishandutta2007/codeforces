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

int N, K, arr[maxN], p[maxN], mn[maxN];

signed main()
{
//	freopen("ball.inp", "r", stdin);
//	freopen("ball.out", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
		cin >> N >> K;
	loop(i, 1, N) cin >> arr[i];
	int l = 0, r = INT_MAX / 2;
	while(l < r)
	{
		bool ok = 0;
		int m = (l + r) / 2;
		loop(i, 1, N)
		{
			p[i] = arr[i] > m;
			p[i] = p[i - 1] + p[i];
			mn[i] = min(mn[i - 1], 2 * p[i] - i);
		}
		loop(i, K, N)
		{
			ok |= (2 * p[i] - i > mn[i - K]);
		}
		if(ok) l = m + 1;
		else r = m;
	}
	cout << l << endl;
}