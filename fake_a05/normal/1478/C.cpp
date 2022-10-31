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
int arr[maxN], delta[maxN];
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
		cin >> N; bool ok = 1;
		loop(i, 1, 2 * N)
		{
			cin >> arr[i];
		}
		sort(arr + 1, arr + 2 * N + 1);
		for(int i = 1; i <= 2 * N; i += 2) ok &= arr[i] == arr[i + 1];	
//		cout << "tc: " << tc << endl;
		loop(i, 1, N) arr[i] = arr[2 * i];
		loop(i, 2, N)
		{
			int toLeft = N + i - 1;
			ok &= (arr[i] - arr[i - 1]) % (2 * toLeft - 2 * N) == 0;
			delta[i] = (arr[i] - arr[i - 1]) / (2 * toLeft - 2 * N);
//			cout << delta[i] << endl;
		}
		int sum = 0;
		loop(i, 2, N) sum += delta[i] * (N + 1 - i);
		ok &= (arr[1] - 2 * sum) % (2 * N) == 0;
		delta[1] = (arr[1] - 2 * sum) / (2 * N);
		loop(i, 1, N) ok &= delta[i] > 0;
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}