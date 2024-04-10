#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int front[100005][2];
int vis[100005][2];
vector<int> v[100005];
int instk[100005];
int vi[100005];
bool dfs(int a){
	instk[a]=1;
	vi[a]=1;
	int ret=0;
	for(auto it:v[a]){
		if(instk[it])
		return true;
		if(!vi[it])
		ret|=dfs(it);
	}
	instk[a]=0;
	return ret;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int a;
			scanf("%d",&a);
			v[i].pb(a);
		}
	}
	int s;
	scanf("%d",&s);
	MEM(vis);
	queue<pii> q;
	q.push(mp(s,0));
	while(!q.empty()){
		pii p=q.front();
		q.pop();
		for(auto it:v[p.x]){
			if(!vis[it][1-p.y]){
				q.push(mp(it,1-p.y));
				vis[it][1-p.y]=1;
				front[it][1-p.y]=p.x;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i][1]&&v[i].empty()){
			printf("Win\n");
			vector<int> v;
			int x=i,situ=1;
			v.pb(x);
			while(x!=s||situ!=0){
				x=front[x][situ];
				situ=1-situ;
				v.pb(x);
			}
			while(!v.empty()){
				printf("%d ",v.back());
				v.pop_back();
			}
			return 0;
		}
	}
	if(dfs(s)){
		printf("Draw\n");
		return 0;
	}
	printf("Lose\n");
}