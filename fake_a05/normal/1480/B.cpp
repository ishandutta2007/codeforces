#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb push_back
#define all(x) begin(x), end(x)

#define rand rng
#define sp ' '
#define endl '\n'


#define int long long
const int maxN = 5e5 + 5;
int tc;
int A, B, N, a[maxN], b[maxN];

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while(tc--)
	{
		cin >> A >> B >> N;
		loop(i, 1, N)
		{
			cin >> a[i];
		}
		int mx = 0;
		loop(i, 1, N)
		{
			cin >> b[i];
			int t = b[i] % A == 0? b[i] / A: b[i] / A + 1;
			B -= t * a[i];
			mx = max(mx, a[i]);
		}
		if(B + mx > 0) cout << "YES\n";
		else cout << "NO\n";
	}
}