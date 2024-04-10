#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 1e4 + 20;
const int maxb = 24;

int dp[16777226][2] , x[maxn];

string s[maxn];

int main()
{
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < 3; j++)
			x[i] |= (1 << (s[i][j] - 'a'));
		dp[x[i]][0]++;
	}
	for(int j = 1; j <= maxb; j++)
		for(int i = 0; i < (1 << maxb); i++)
		{
			int x = (j & 1);
			j--;
			if(bit(i , j))
				dp[i][x] = dp[i ^ (1 << j)][1 - x];
			else
			{
				dp[i][x] = dp[i][1 - x];
				if((i + (1 << j)) < (1 << maxb))
					dp[i][x] += dp[i + (1 << j)][1 - x];
			}
			j++;
		}
	ll res = 0;
	for(int i = 0; i < (1 << maxb); i++)
	{
/*		int k = 0;
		for(int j = 0; j < n; j++)
			if(!(x[j] & i))
				k++;
		if(k != dp[i][1])
		{
//			cout << i << " SHIT" << endl;
//			break;
		}*/
		res ^= (n - dp[i][0]) * (n - dp[i][0]);
	}
//	cout << dp[0][5] << " " << dp[1][5] << endl;
	cout << res << endl;
}