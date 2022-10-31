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

const int maxN = 3e5 + 5, mod = 1e9 + 7;

int N, b[maxN], pref[maxN], dp[maxN]; 
map<int, int> lt;
int lt_sum;
void upd(int v, int d)
{
	lt_sum -= lt[v];
	lt[v] = d;
	lt_sum += lt[v];
	lt_sum = (lt_sum % mod + mod) % mod;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> N;
		loop(i, 1, N) dp[i] = 0;
		lt.clear();
		lt_sum = 0;
		loop(i, 1, N)
		{
			cin >> b[i];
			pref[i] = pref[i - 1] + b[i];
		}
		dp[1] = 1;
		upd(0, 1);
		loop(i, 2, N)
		{
			dp[i] = lt_sum;
			upd(pref[i - 1], lt_sum);
		}
		cout << lt_sum << endl;
	}
}