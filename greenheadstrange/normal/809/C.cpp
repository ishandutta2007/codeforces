#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long 
using namespace std;
#define maxw 32
#define mod 1000000007
ll num[3][maxw];
ll dp[2][2][2][maxw], s[2][2][2][maxw];
// 1 : 
// 0 :  
//a b k
ll work(ll a, ll b, ll k)
{
//	cout<<a<<" "<<b<<" "<<k<<endl;
	if(a < 0 || b < 0) return 0;
	for(ll i = 0; i < maxw; i++)
		num[0][i] = (a & 1), a >>= 1, 
		num[1][i] = (b & 1), b >>= 1, 
		num[2][i] = (k & 1), k >>= 1;
	memset(dp, 0, sizeof(dp));
	memset(s, 0, sizeof(s));
	for(ll i = 0; i < maxw; i++)	
	{
		ll nm[2][2] = {{1, num[0][i]}, {1, num[1][i]}};
		for(ll m = 0; m < 2; m++)
			for(ll j = 0; j < 2; j++)
				for(ll n = 0; n < 2; n++)
				{
					for(ll k = 0; k <= nm[0][m]; k++)
						for(ll l = 0; l <= nm[1][j]; l++)
						{
							if((k ^ l) > num[2][i] && n) 
								continue;	
							ll f1 = (k == num[0][i] && m);
							ll f2 = (l == num[1][i] && j);
							ll f3 = (((k ^ l) == num[2][i]) && n);
							if(i)
								s[m][j][n][i] += s[f1][f2][f3][i - 1], s[m][j][n][i] %= mod, 
								dp[m][j][n][i] += (((ll)(k ^ l)) << i) * s[f1][f2][f3][i - 1] + dp[f1][f2][f3][i - 1], dp[m][j][n][i] %= mod;
							else
								s[m][j][n][i]++,
								dp[m][j][n][i] += (((ll)(k ^ l)) << i), dp[m][j][n][j] %= mod;
						//	if(m && j && n && i) cout<<"PLUS"<<k<<" "<<l<<" "<<f1<<" "<<f2<<" "<<f3<<endl;
						}
				//	cout<<m<<" "<<j<<" "<<n<<" "<<i<<" "<<dp[m][j][n][i]<<" "<<s[m][j][n][i]<<endl;
				}
 	}
 	return dp[1][1][1][maxw - 1] + s[1][1][1][maxw - 1];
}
int main()
{
	ll q;
	scanf("%I64d", &q);
	for(ll i = 0; i < q; i++)
	{
		ll x1, y1, x2, y2, k;
		scanf("%I64d%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2, &k);
		k--;
		x1--, x2--, y1--, y2--;
		ll ans = 0;
		ans += work(x2, y2, k);
		ans -= work(x1 - 1, y2, k);
		ans -= work(x2, y1 - 1, k);
		ans += work(x1 - 1, y1 - 1, k);
		ans %= mod;
		if(ans < 0) ans += mod;
	//	ans += (x2 - x1 + 1) * (y2 - y1 + 1);
		printf("%I64d\n", ans);
	}
	return 0;
}
/*
4
3 2 5 4 1
*/