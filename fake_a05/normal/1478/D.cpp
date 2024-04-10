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
const int maxN = 2e5 + 5;

int tc, N, K;
int arr[maxN];
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
		cin >> N >> K;
		loop(i, 1, N) cin >> arr[i];
		sort(arr + 1,arr + N + 1);
		int tmp = arr[2] - arr[1];
		loop(i, 2, N) tmp = __gcd(tmp, arr[i] - arr[i - 1]);
		if((K - arr[1]) % tmp == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}