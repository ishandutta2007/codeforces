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
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
vector<int> lucky;
void dfs(int sum){
	if(sum>100000)
	return;
	if(sum!=0)
	lucky.pb(sum);
	dfs(sum*10+4);
	dfs(sum*10+7);
}
vector<int> v[100005];
int vis[100005];
int travel(int n){
	int sum=1;
	vis[n]=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!vis[*it])
		sum+=travel(*it);
	}
	return sum;
}
int dp[100005];
int main(){
	dfs(0);
	int n,m;
	scanf("%d %d",&n,&m);
	MEM(vis);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	map<int,int> region;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int x=travel(i);
			region[x]++;
		}
	}
	MEMS(dp);
	dp[0]=0;
	for(map<int,int>::iterator it=region.begin();it!=region.end();it++){
		for(int i=0;i<it->x;i++){
			deque<pii> q;
			for(int j=i;j<=n;j+=it->x){
				if(dp[j]!=-1){
					while(!q.empty()){
						pii p=q.back();
						if(p.x+(p.y-j)/it->x>dp[j])
						q.pop_back();
						else
						break;
					}
					q.push_back(mp(dp[j],j));
				}
				if(!q.empty()&&(j-q.front().y)/it->x>it->y)
				q.pop_front();
				if(!q.empty()){
					if(dp[j]==-1)
					dp[j]=q.front().x+(j-q.front().y)/it->x;
					else{
						dp[j]=min(q.front().x+(j-q.front().y)/it->x,dp[j]);
					}
				}
			}
		}
	}
//	for(int i=0;i<=n;i++)
	//printf("%d ",dp[i]);
	int ans=1e9;
	for(vector<int>::iterator it=lucky.begin();it!=lucky.end();it++){
	//	printf("%d\n",*it);
		if(dp[*it]!=-1) 
			ans=min(ans,dp[*it]);
	} 
	if(ans==1e9)
	printf("-1\n");
	else
	printf("%d\n",ans-1);
}