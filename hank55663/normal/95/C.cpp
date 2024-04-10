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
int cost[1005][1005];
vector<pii> v[1005];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int x,y;
	scanf("%d %d",&x,&y);
	for(int i=0;i<m;i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w); 
		v[a].pb(mp(b,w));
		v[b].pb(mp(a,w));
	}
	MEMS(cost);
	for(int i=1;i<=n;i++){
		int t,c;
		scanf("%d %d",&t,&c);
		priority_queue<pii> pq;
		pq.push(mp(t,i));
		int vis[1005];
		MEM(vis);
		while(!pq.empty()){
			pii p=pq.top();
			pq.pop();
			if(vis[p.y])
			continue;
			if(cost[i][p.y]==-1)
			cost[i][p.y]=c;
			else
			cost[i][p.y]=min(cost[i][p.y],c);
			vis[p.y]=1;;
			for(vector<pii>::iterator it=v[p.y].begin();it!=v[p.y].end();it++){
				if(it->y<=p.x&&!vis[it->x]){
					pq.push(mp(p.x-it->y,it->x));
				} 
			}
		}
	}
	for(int i=1;i<=n;i++)
		cost[i][i]=0;
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	pq.push(mp(0,x));
	int vis[1005];
	MEM(vis);
	while(!pq.empty()){
		pll p = pq.top();
		pq.pop();
		if(vis[p.y])
		continue;
		if(p.y==y){printf("%I64d\n",p.x);
		return 0;
		}
		vis[p.y]=1;
		for(int i=1;i<=n;i++){
			if(cost[p.y][i]!=-1&&!vis[i]){
				pq.push(mp(p.x+cost[p.y][i],i));
			}
		}
	} 
	printf("-1\n");
}