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
const int maxN = 105;
int tc, N, K;
int h[maxN];
signed main()
{
//	freopen("return.in", "r", stdin);
//	freopen("return.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> N >> K;
		loop(i, 1, N) cin >> h[i];
		loop(k, 1, K)
		{
			int pos = 1;
			while(1)
			{
				if(pos == N + 1) break;
				if(pos == N or h[pos + 1] <= h[pos]) pos++;
				else 
				{
					h[pos]++;
					break;
				}
			}
			if(pos == N + 1) 
			{
				cout << -1 << endl;
				break;
			}
			if(k == K) cout << pos << endl;
		}
	}
}