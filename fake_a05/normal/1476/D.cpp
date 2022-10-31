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
const int maxN = 3e5 + 5;
int tc, N;
string s;
int dpLeft[maxN][2], dpRight[maxN][2];
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
		cin >> N >> s;
		s = '$' + s;
		loop(i, 0, N)
		{
			loop(par, 0, 1)
			{
				if(!i) dpLeft[i][par] = 0;
				else if((s[i] == 'R' and par == 0) or (s[i] == 'L' and par == 1)) dpLeft[i][par] = 0;
				else dpLeft[i][par] = dpLeft[i - 1][par ^ 1] + 1;
			}
		}
		rloop(i, N, 0)
		{
			loop(par, 0, 1)
			{
				if(i == N) dpRight[i][par] = 0;
				else if((s[i + 1] == 'L' and par == 0) or (s[i + 1] == 'R' and par == 1)) dpRight[i][par] = 0;
				else dpRight[i][par] = dpRight[i + 1][par ^ 1] + 1;
			}
		}
		loop(i, 0, N) cout << dpLeft[i][0] + dpRight[i][0] + 1 << sp;
		cout << endl;
	}
}