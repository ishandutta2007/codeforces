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
using namespace std;
vector<int> v[200005];
int dis[200005];
int Max[200005],Min[200005];
vector<vector<int> > node;
int d;
int a[200005];
void dfs(int x,int f){
	dis[x]=dis[f]+1;
	d=max(d,dis[x]);
	node[dis[x]].pb(x);
	Max[dis[x]]=max(Max[dis[x]],a[x]);
	Min[dis[x]]=min(Min[dis[x]],a[x]);
	//printf("%d %d\n",x,dis[x]);
	for(auto it:v[x]){
		if(it!=f)
		dfs(it,x);
	}
}

bool cmp(const int x,const int y){
	return a[x]<a[y];
}
LL dp[200005];
bool solve(){
	int n;
	scanf("%d",&n);
	d=0;
	for(int i = 1;i<=n;i++)v[i].clear(),Max[i]=0,Min[i]=1e9;
	node.clear();
	node.resize(n+1);
	for(int i = 2;i<=n;i++){
		int x;
		scanf("%d",&x);
		v[x].pb(i);
		v[i].pb(x);
	}
	for(int i = 2;i<=n;i++)scanf("%d",&a[i]);
	dfs(1,0);
	LL ans=0;
	for(int i = d;i>1;i--){
		sort(node[i].begin(),node[i].end(),cmp);
		if(i==d){
			for(auto it:node[i]){
				dp[it]=max(Max[i]-a[it],a[it]-Min[i]);
			}
		}
		LL Maxval=-Min[i];
		for(auto it:node[i]){
			dp[it]=Maxval+a[it];
			for(auto it2:v[it]){
				if(dis[it2]==dis[it]+1){
					dp[it]=max(dp[it],dp[it2]+max(Max[i]-a[it],a[it]-Min[i]));
					Maxval=max(Maxval,dp[it2]-a[it]);
				}
			}
		}
		reverse(node[i].begin(),node[i].end());
		Maxval=Max[i];
		for(auto it:node[i]){
			dp[it]=max(Maxval-a[it],dp[it]);
			for(auto it2:v[it]){
				if(dis[it2]==dis[it]+1){
					dp[it]=max(dp[it],dp[it2]+max(Max[i]-a[it],a[it]-Min[i]));
					Maxval=max(Maxval,dp[it2]+a[it]);
				}
			}
			ans=max(ans,dp[it]);
		//	printf("%d %d\n",it,dp[it]);
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}