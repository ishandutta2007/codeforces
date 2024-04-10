#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
int n,m,k,mod,C[N][N],p[N],dp[N][N][N];
int dfs(int a,int b,int c){
	if(a<c)return 0;
	if(!a&&!c)return 1;
	if(b==1)return c==1?p[a]:0;
	if(dp[a][b][c]!=-1){
		return dp[a][b][c];
	}
	int tmp=0;
	for(int i=1;i<=a;++i){
		for(int j=max(0,i+c-a);j<i&&j<=c;++j){
			tmp=(tmp+1LL*dfs(i-1,b-1,j)*dfs(a-i,b-1,c-j)%mod*C[a-1][i-1])%mod;
		}
	}
	return dp[a][b][c]=tmp;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k>>mod;
	C[0][0]=1;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	p[0]=p[1]=1;
	for(int i=2;i<=n;++i){
		for(int j=0;j<i;++j){
			p[i]=(p[i]+1LL*p[j]*p[i-j-1]%mod*C[i-1][j])%mod;
		}	
	}
	cout<<dfs(n,m,k)<<endl;
	return 0;
}