#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
vector<pii> v[100005];
vector<int> scc[100005];
int nscc;
vector<int> stk;
int vis[100005];
int lw[100005];
int t;
pii p[100005];
int ok[100005];
void dfs(int a){
	vis[a]=lw[a]=++t;
	for(auto it:v[a]){
		if(!ok[it.y]){
			ok[it.y]=1;
			stk.pb(it.y);
			if(!vis[it.x]){
				dfs(it.x);
				if(lw[it.x]>=vis[a]){
					while(stk.back()!=it.y){
						scc[nscc].pb(stk.back());
						stk.pop_back();
					}
					scc[nscc++].pb(stk.back());
					stk.pop_back();
				}
				lw[a]=min(lw[a],lw[it.x]);
			}
			else{
				lw[a]=min(vis[it.x],lw[a]);
			}
		}
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		p[i]=mp(a,b);
		v[a].pb(mp(b,i));
		v[b].pb(mp(a,i));
	}
	t=0;
	nscc=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	int node [100005];
	MEM(node);
	vector<int> ans;
	for(int i=0;i<nscc;i++){
		int cnt=0;
		for(auto it:scc[i]){
			if(node[p[it].x]!=i+1){
				cnt++;
				node[p[it].x]=i+1;
			}
			if(node[p[it].y]!=i+1){
				cnt++;
				node[p[it].y]=i+1;
			}
		}
		if(cnt==scc[i].size()){
			for(auto it:scc[i])
				ans.pb(it);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto it:ans)
	printf("%d ",it);
}