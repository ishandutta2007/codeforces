#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int MAXP = MAXN + MAXM*5 *2;
const int mod = 1e9 + 7;
using namespace std;

vector<int> to[MAXP][11];
int pcnt=0;

inline void add_e(int u,int v,int i)
{
	int lst=v;
	while(i/10)
	{
		to[++pcnt][i%10].push_back(lst);
		lst=pcnt;
		i/=10;
	}
	to[u][i].push_back(lst);
}
inline void add(int u,int v,int w){ add_e(u,v,w); add_e(v,u,w);}

ll dis[MAXP];
queue< vector<int> > q;
vector<int> vec,vec2;
void bfs(void)
{
	memset(dis,-1,sizeof(dis));
	
	dis[1]=0;
	vec.push_back(1);
	q.push(vec);
	
	while(!q.empty())
	{
		vec=q.front(); q.pop();
		for(int k=0; k<=9; ++k)
		{
			vec2.clear();
			for(int i=0; i<(int)vec.size(); ++i)
			{
				int u=vec[i];
				for(int j=0; j<(int)to[u][k].size(); ++j)
				{
					int v=to[u][k][j];
					if(dis[v]==-1)
					{
						dis[v]=(dis[u]*10+k)%mod;
						vec2.push_back(v);
					}
				}
			}
			if(vec2.size()) q.push(vec2);
		}
	}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	pcnt=n;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,i);
	}
	
	bfs();
	for(int i=2; i<=n; ++i) printf("%d\n",(int)dis[i]);
	return 0;
}