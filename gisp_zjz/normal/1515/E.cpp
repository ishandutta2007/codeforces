#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
typedef long long ll;
const int maxn=411;
int C[maxn][maxn],n,M,dp[maxn][maxn],p2[maxn],ans;
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
int main(){
	C[0][0]=1;
	cin >> n >> M;
	for (int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	}
	p2[0]=1; for (int i=1;i<=n;i++) p2[i]=p2[i-1]*2%M;
	for (int i=1;i<=n;i++) dp[i][i]=p2[i-1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			for (int k=1;k<j;k++)
				add(dp[i][j],1ll*dp[i-k-1][j-k]*C[j][k]%M*p2[k-1]%M);
    ans=0;
    for (int i=1;i<=n;i++) add(ans,dp[n][i]);
    //for (int i=1;i<=n;i++)cout<<dp[n][i]<<' ';cout<<endl;
    cout << ans << endl;
	return 0;
}