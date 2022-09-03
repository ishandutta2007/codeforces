#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<int> v[200005];
int dep[200005];
vector<int> vv[2];
int vis[200005];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	vv[dep[x]&1].pb(x);
	vis[x]=1;
	for(auto it:v[x]){
		if(it!=f&&!vis[it]){
			dfs(it,x);
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i = 1;i<=n;i++){
			v[i].clear();
			vis[i]=0;
		}
		for(int i = 1;i<=m;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			v[x].pb(y);
			v[y].pb(x);
		}
		dfs(1,0);
		if(vv[0].size()>vv[1].size()){
			swap(vv[0],vv[1]);
		}
		printf("%d\n",vv[0].size());
		for(auto it:vv[0])
		printf("%d ",it);
		printf("\n");
		vv[0].clear();
		vv[1].clear();
	}
}
/*
aaaa
aaba
abaa
baaa
baba
*/