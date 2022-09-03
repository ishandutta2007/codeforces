#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define index Index
using namespace std;
LL dp[605][605];
LL Max[605][605];
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)dp[i][j]=1e18,Max[i][j]=-1e18;
		dp[i][i]=0;
	}
	vector<pair<pii,int> > v;
	for(int i=0;i<m;i++){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		dp[x][y]=dp[y][x]=w;
		v.pb(mp(mp(x,y),w));
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int u,v,l;
		scanf("%d %d %d",&u,&v,&l);
		for(int i = 1;i<=n;i++){
			Max[u][i]=max(Max[u][i],l-dp[i][v]);
			Max[v][i]=max(Max[v][i],l-dp[i][u]);
		}
	}
	int ans=0;
	for(auto it:v){
		int ok=0;
		for(int i = 1;i<=n;i++){
			if(Max[i][it.x.y]-it.y-dp[i][it.x.x]>=0)ok=1;
			if(Max[i][it.x.x]-it.y-dp[i][it.x.y]>=0)ok=1;
		}
		ans+=ok;
	}
	printf("%d\n",ans);
	return true;
}
int main(){
	int t=1;//0000;//000000;
	//scanf("%d",&t);
	while(t--)solve();
}