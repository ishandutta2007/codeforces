#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int K;
long long dp[110][23][23];
vector<int>g[110];
long long dp2[110][23][23];
void calc(int a,int b){
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		calc(g[a][i],a);
	}
	int t=0;
	for(int i=0;i<110;i++)for(int j=0;j<23;j++)for(int k=0;k<23;k++)dp2[i][j][k]=0;
	dp2[0][K+1][1]=1;
	dp2[0][0][0]=1;
	
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i])continue;
		for(int j=0;j<=K+1;j++){
			for(int k=0;k<=K;k++){
				if(!dp2[t][j][k])continue;
				for(int l=0;l<=K+1;l++)for(int m=0;m<=K;m++){
					if(!dp[g[a][i]][l][m])continue;
					int tj=j;int tk=k;
					tj=min(tj,l+1);
					if(tj+k-1<=K)tk=0;
					if(m&&tj+m>K)tk=max(tk,m+1);
					dp2[t+1][tj][tk]=(dp2[t+1][tj][tk]+dp2[t][j][k]*dp[g[a][i]][l][m])%mod;
				}
			}
		}
		t++;
	}
	/*for(int j=0;j<=K+1;j++){
		for(int k=0;k<=K;k++){
			int tj=j;int tk=k;
			if(tj==K+1)tk++;
			dp2[t+1][tj][tk]=(dp2[t+1][tj][tk]+dp2[t][j][k])%mod;
			dp2[t+1][0][0]=(dp2[t+1][0][0]+dp2[t][j][k])%mod;
		}
	}
	t++;*/
	for(int i=0;i<=K+1;i++)for(int j=0;j<=K;j++)dp[a][i][j]=dp2[t][i][j];
//	for(int i=0;i<=K+1;i++)for(int j=0;j<=K;j++){
//		if(dp[a][i][j])printf("%d %d %d: %I64d\n",a,i,j,dp[a][i][j]);
//	}
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	K=b;
	for(int i=0;i<a-1;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	calc(0,-1);
	long long ret=0;
	for(int i=0;i<=K+1;i++)ret=(ret+dp[0][i][0])%mod;
	printf("%I64d\n",ret);
}