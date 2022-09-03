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
vector<pii> v[105];
int a[105][105];
int idx[105];
int vis[100005];
vector<int> ans;
void dfs(int x){
	while(idx[x]!=v[x].size()){
		if(!vis[v[x][idx[x]].y]){
		vis[v[x][idx[x]].y]=1;
		int a=v[x][idx[x]].x;
		idx[x]++;
		dfs(a);
		}
		else{
			idx[x]++;
		}
	}
	ans.pb(x);
}
void solve(){
	MEM(a);
	for(int i = 0;i<105;i++)v[i].clear(),idx[i]=0;
	fill(vis,vis+100005,0);
	ans.clear();
	int n;
	scanf("%d",&n);
	if(n%2==0){
		int index=0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(i%2!=1||j!=i+1){
					v[i].pb(mp(j,index));
					v[j].pb(mp(i,index++));
				}
			}
		}
		dfs(1);
		for(int i = 0;i+1<ans.size();i++){
			a[ans[i]][ans[i+1]]=1;
			a[ans[i+1]][ans[i]]=-1;
		}
	}
	else{
		int index=0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				v[i].pb(mp(j,index));
				v[j].pb(mp(i,index++));
			}
		}
		dfs(1);
		for(int i = 0;i+1<ans.size();i++){
			a[ans[i]][ans[i+1]]=1;
			a[ans[i+1]][ans[i]]=-1;
			//printf("%d ",ans[i]);
		}
		//printf("%d\n",ans.back());
	}
	int sc[105];
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			printf("%d ",a[i][j]);
			if(a[i][j]==0)sc[i]++,sc[j]++;
			else if(a[i][j]==1)sc[i]+=3;
			else sc[j]+=3;
		}
	}
	//printf("\n");
	//for(int i = 1;i<=n;i++)printf("%d ",sc[i]);
	printf("\n");
}
int main(){
    int t=1;00000;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 2 3 4 5 6 7
1 3 5 7 2 4 6
0 3 6 2 5 1 4
*/