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
const int maxN = 1e2 + 5;
int tc, N, K;
int p[maxN];
bool check()
{
	int sum = p[0];
	loop(i, 1, N)
	{
		if(p[i] * 100 > K * sum) return 0;
		sum += p[i];
	}
	return 1;
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
		cin >> N >> K; N--;
		loop(i, 0, N) cin >> p[i];
		int low = 0, high = 1e13;
		while(low < high)
		{
			int M = low + high >> 1;
			p[0] += M;
			if(check()) high = M;
			else low = M + 1;
			p[0] -= M;
		 } 
		 cout << low << endl;
	}
}