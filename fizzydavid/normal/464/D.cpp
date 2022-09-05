//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int C=550;
int n,k;
double dp[2][1000];
int main()
{
	cin>>n>>k;
	for(int i=1;i<C;i++)dp[0][i]=0;
	for(int _=1;_<=n;_++)
	{
		int i=_&1;
		for(int j=1;j<C-1;j++)
			dp[i][j]=1.0*(k-1)/k*dp[i^1][j]+1.0/k*(1.0/(j+1)*(dp[i^1][j+1]+j)+1.0*j/(j+1)*(dp[i^1][j]+(j+1)/2.0));
	}
	cout<<fixed<<setprecision(12)<<dp[n&1][1]*k<<endl;
	return 0;
}