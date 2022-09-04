#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int dp[5005][5005];
int main(){	
	int n;
	scanf("%d",&n);
	int a[5005];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	MEM(dp);
	int ans=0;
	pii m[100005];
	MEM(m);
	for(int i=0;i<=n;i++){
		int mod[7];
		int Mi;
		MEM(mod);
		for(int j=0;j<=n;j++){
			if(i==j)
			dp[i][j]=0;
			else if(i>j){
				dp[i][j]=dp[j][i];
			}
			else{
				int Ma=0;
				if(m[a[j]-1].x==i)
					Ma=max(Ma,m[a[j]-1].y);
				if(m[a[j]+1].x==i)
					Ma=max(m[a[j]+1].y,Ma);
				dp[i][j]=max(mod[a[j]%7],max(Ma,Mi))+1;
			}
			if(j==0)
				Mi=dp[i][j];
			else{
				mod[a[j]%7]=max(mod[a[j]%7],dp[i][j]);
				m[a[j]]=max(mp(i,dp[i][j]),m[a[j]]);
				if(i!=0&&j!=0)
				ans=max(ans,dp[i][j]);
			}
		//	printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	printf("%d\n",ans);
}