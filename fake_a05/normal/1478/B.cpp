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

int tc, N, D;
vi Lucky;
bool can[1000];
bool good(int x){
	while(x)
	{
		if(x % 10 == D) return 1;
		x /= 10;
	}
	return 0;
}
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
		cin >> N >> D;
		fill(all(can), 0);
		Lucky.clear();
		loop(i, 1, 999) if(good(i)) Lucky.eb(i);
		can[0] = 1;
		for(int a: Lucky)
		{
			loop(i, a, 999) can[i] |= can[i - a];
		}
		while(N--)
		{
			int x;
			cin >> x;
			if(x >= 1000 or can[x]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}