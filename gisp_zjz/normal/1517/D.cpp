#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=600;
const int M=998244353;
void Min(int &x,int y){
	if (y<x) x=y;
}
int dp[maxn][maxn][22];
int n,m,k,r[maxn][maxn],c[maxn][maxn];
int main(){
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<m;j++)
			cin >> r[i][j]; // (i,j) -> (i,j+1)

	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++)
			cin >> c[i][j]; // (i,j) -> (i+1,j)

    if (k%2){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) printf("-1 ");puts("");
		}
    } else {
		k/=2;
        for (int p=1;p<=k;p++)
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			dp[i][j][p]=1e9;
			if (i>1) Min(dp[i][j][p],dp[i-1][j][p-1]+c[i-1][j]);
			if (i<n) Min(dp[i][j][p],dp[i+1][j][p-1]+c[i][j]);
			if (j>1) Min(dp[i][j][p],dp[i][j-1][p-1]+r[i][j-1]);
			if (j<m) Min(dp[i][j][p],dp[i][j+1][p-1]+r[i][j]);
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) printf("%d ",2*dp[i][j][k]);puts("");
		}
    }
    return 0;
}