#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
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
const int inf=1e9+5, nax=1e6+5;

char sl[2005], wzor[505];

int dp[2005][2005];
int res[2005];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> sl >> wzor;
	int sd = strlen(sl);
	int wzord = strlen(wzor);
	
	RE(i, sd + 2) RE(x, sd + 2) dp[i][x] = inf;
	dp[0][0] = 0;
	RE(i, sd) RE(j, sd) {
		if(sl[i] == wzor[j % wzord])
			mini(dp[i + 1][j + 1], dp[i][j]);
		
		if(j % wzord == 0) mini(dp[i + 1][j], dp[i][j]);
		else mini(dp[i + 1][j], dp[i][j] + 1);
	}
	
	for(int k = 0; wzord * k <= sd; ++k) {
		for(int i = dp[sd][k * wzord]; i <= sd - k * wzord; ++i)
			maxi(res[i], k);
	}
	RE(i, sd + 1) cout << res[i] << " ";
	return 0;
}