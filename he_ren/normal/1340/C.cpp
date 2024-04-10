#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
const int MAXM = 1e4 + 5;
const int MAXG = 1e3 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int n,m,g,r;
int d[MAXM];

struct Node
{
	int x,y;
	ll dis;
	inline friend bool operator < (const Node &p,const Node &q){ return p.dis>q.dis;}
};
bool vis[MAXM][MAXG];
ll dis[MAXM][MAXG];
priority_queue<Node> q;

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d",&d[i]);
	sort(d+1,d+m+1);
	scanf("%d%d",&g,&r);
	
	memset(dis,0x3f,sizeof(dis));
	for(int i=1; i<=g; ++i)
		dis[m][i] = 0,
		q.push((Node){m,i,0});
	while(!q.empty())
	{
		Node now = q.top(); q.pop();
		int x=now.x, y=now.y;
		if(vis[x][y]) continue;
		vis[x][y]=1;
		
		if(x>1)
		{
			int tmp = d[x]-d[x-1];
			
			ll nxt = dis[x][y] + tmp;
			if(y==g && x!=m) nxt += r;
			
			int yy = (y==g)? tmp: tmp+y;
			
			if(yy<=g && nxt < dis[x-1][yy])
				dis[x-1][yy] = nxt,
				q.push((Node){x-1,yy, nxt});
		}
		if(x<m)
		{
			int tmp = d[x+1]-d[x];
			
			ll nxt = dis[x][y] + tmp;
			if(y==g && x!=m) nxt += r;
			
			int yy = (y==g)? tmp: tmp+y;
			
			if(yy<=g && nxt < dis[x+1][yy])
				dis[x+1][yy] = nxt,
				q.push((Node){x+1,yy, nxt});
		}
	}
	
	if(dis[1][g] == linf) printf("-1");
	else printf("%lld",(ll)dis[1][g]);
	return 0;
}