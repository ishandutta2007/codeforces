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
int dis[100005][52];
int inq[100005][52];
vector<pii> v[100005];
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		v[x].pb(mp(y,w));
		v[y].pb(mp(x,w));
	}
//	priority_queue<pair<int,pii>,vector<pair<int,pii> > ,greater<pair<int,pii> > > pq;
	deque<pii> q;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=50;j++)dis[i][j]=2e9+77;
	}
	dis[1][0]=0;
	//MEMS(dis);
	q.pb(mp(1,0));
	while(!q.empty()){
		auto p=q.front();
		if(dis[p.x][p.y]>dis[q.back().x][q.back().y]){
			p=q.back();
			q.pop_back();
		}
		else
			q.pop_front();
		//if(dis[p.y.x][p.y.y]!=-1)continue;
		//dis[p.y.x][p.y.y]=p.x;
		inq[p.x][p.y]=0;
		for(auto it:v[p.x]){
			if(p.y==0){
				if(dis[it.x][it.y]>dis[p.x][p.y]){
					dis[it.x][it.y]=dis[p.x][p.y];
					if(!inq[it.x][it.y]){
						inq[it.x][it.y]=1;
						q.push_back(it);
						//pq.push(mp(p.x,it));
					}
				}
			}
			else{
				if(dis[it.x][0]>dis[p.x][p.y]+(it.y+p.y)*(it.y+p.y)){
					dis[it.x][0]=dis[p.x][p.y]+(it.y+p.y)*(it.y+p.y);
					if(!inq[it.x][0]){
						inq[it.x][0]=1;
						q.push_back(mp(it.x,0));
					}
				}
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(dis[i][0]==2e9+77)
		printf("-1 ");
		else
		printf("%d ",dis[i][0]);
	}
	printf("\n");
	return true;
}
int main(){
	int t=1;//000000;
    //scanf("%d",&t);
    while(t--)solve();
}