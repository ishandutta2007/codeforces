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

const int maxN = 1e2 + 5;

int tc, N, arr[maxN];

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
		int cnt = 0, ans = 0;
		loop(i, 1, N)
		{
			cin >> arr[i];
			if(i == 1 or arr[i] == arr[i - 1]) cnt++;
			else cnt = 1;
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
}