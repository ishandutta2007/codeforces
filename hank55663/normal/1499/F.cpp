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
const int mod=998244353;
int dp[5005][5005];
int dp2[5005][5005];
vector<int> v[5005];
int Max[5005];
int p[5005];
int k;
void dfs(int x,int f){
	p[x]=f;
	Max[x]=0;
	dp[x][0]=1;
	for(auto it:v[x]){
		if(it!=f){
			dfs(it,x);
			Max[x]=max(Max[x],Max[it]+1);
			dp[x][0]=dp[x][0]*1ll*dp2[it][Max[it]]%mod;
		}
	}	
	for(int i = 1;i<=Max[x]&&i<=k;i++){
		if(i+i<=k){
			dp[x][i]=1;
			for(auto it:v[x]){
				if(it!=f)
				dp[x][i]=dp[x][i]*1ll*(dp2[it][min(i-1,Max[it])]+dp2[it][Max[it]])%mod;
			}
			//printf("%d ",dp[x][i]);
			//dp[x][i]-=dp[x][i-1];
			dp[x][i]=(dp[x][i]%mod+mod)%mod;
		}
		else{
			dp[x][i]=0;
			LL tot1=1,tot2=0;
			for(auto it:v[x]){
				if(it!=f){
				if(k==i){
					tot2=(tot2*(dp2[it][Max[it]])+tot1*(dp[it][i-1]))%mod;
					tot1*=(dp2[it][Max[it]]);
				}
				else{
					tot2=(tot2*(dp2[it][min(k-i-1,Max[it])]+dp2[it][Max[it]])+tot1*(dp[it][i-1]))%mod;
					tot1*=(dp2[it][min(k-i-1,Max[it])]+dp2[it][Max[it]]);
				}
				tot1%=mod;
				}
			}
			dp[x][i]=tot2;
		}
	}
	for(int i = Max[x];i>=1;i--){
		if(i+i<=k){
			dp[x][i]-=dp[x][i-1];
			dp[x][i]=(dp[x][i]%mod+mod)%mod;
		}
	}
	for(int i = 0;i<=Max[x];i++){
		dp2[x][i]=dp[x][i];
		if(i!=0)dp2[x][i]+=dp2[x][i-1],dp2[x][i]%=mod;
	//	printf("%d ",dp[x][i]);
	}
	//printf("%d\n",x);
}
int ok[1005];
int dfs2(int x,int f){
	int Max=0;
	for(auto it:v[x]){
		if(it==f)continue;
		if(it!=p[x]){
			if(ok[it]){
				Max=max(Max,dfs2(it,x)+1);
			}
		}
		else{
			if(ok[x]){
				Max=max(Max,dfs2(it,x)+1);
			}
		}
	}
	return Max;
}
bool solve(){
	int n;
	scanf("%d %d",&n,&k);
//	srand(time(NULL));
	for(int i = 1;i<n;i++){
		int x=i+1,y=rand()%i+1;
	//	printf("%d %d\n",x,y);
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	LL ans=0;
	for(int i = 0;i<=k;i++){
		ans+=dp[1][i];
		ans%=mod;
	}
	printf("%lld\n",ans);
/*	int ans2=0;
	for(int i = 1;i<(1<<n);i+=2){
		for(int j = 0;j<n;j++){
			if(i&(1<<j))ok[j+1]=1;
			else ok[j+1]=0;
		}
		int add=1;
		for(int j = 0;j<n;j++){
			if(dfs2(j+1,0)>k)add=0;
		}
		ans2+=add;
	}
	printf("%lld\n",ans2);*/
	return true;
}
int main(){
	int t=1;//000000;
	//scanf("%d",&t);
	while(t--)solve();
}