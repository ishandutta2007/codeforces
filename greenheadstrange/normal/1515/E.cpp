//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 505 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y) {return x > y ? x = y, true : false;}

using namespace std;

int n,m;
ll dp[maxn][maxn];
int main() {
	scanf("%d%d",&n,&m);
	dp[1][1]=1;
	for (int i=1;i<n;i++) {
		for (int j=1;j<=i;j++) {
			dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%m;
			if (j>1) dp[i+2][j-1]=(dp[i+2][j-1]+dp[i][j]*j*(j-1)*2)%m;
			if (j>1) dp[i+3][j-1]=(dp[i+3][j-1]+dp[i][j]*j*(j-1))%m;
			dp[i+1][j]=(dp[i+1][j]+dp[i][j]*j*2)%m;
			dp[i+2][j]=(dp[i+2][j]+dp[i][j]*j*2)%m;
		}
	}
	printf("%lld\n",dp[n][1]);
}