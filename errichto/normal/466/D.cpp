#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5, N = 2005;
const ll mod = 1000 * 1000 * 1000 + 7;

int t[N];
ll dp[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, h;
	cin >> n >> h;
	RI(i, n) cin >> t[i];
	dp[1][0] = 1;
	RI(i, n) {
		RE(zacz, i) {
			if(t[i] + zacz + 1 == h) dp[i + 1][zacz + 1] += dp[i][zacz];
			if(t[i] + zacz == h) dp[i + 1][zacz] += dp[i][zacz];
			if(t[i] + zacz + 1 == h) dp[i + 1][zacz] += (zacz + 1LL) * dp[i][zacz];
			if(t[i] + zacz == h && zacz > 0) dp[i + 1][zacz - 1] += zacz * dp[i][zacz];
			dp[i + 1][zacz] %= mod;
			if(zacz > 0) dp[i + 1][zacz - 1] %= mod;
			dp[i + 1][zacz + 1] %= mod;
		}
	}
	cout << dp[n + 1][0];
	return 0;
}