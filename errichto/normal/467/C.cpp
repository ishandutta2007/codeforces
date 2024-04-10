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
const int inf=1e9+5, nax=5e3+5;

ll dp[nax][nax];
ll t[nax];
ll s[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, d, k;
	cin >> n >> d >> k;
	RI(i, n) {
		cin >> t[i];
		s[i] = s[i-1] + t[i];
	}
	RI(i, n) RI(j, k)
		dp[i][j] = max(dp[i-1][j], i - d < 0 ? 0 : dp[i - d][j-1] + s[i] - s[i - d]);
	cout << dp[n][k];
	return 0;
}