#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned int uint;
const int MAXN = 24 + 5;
const int ALL = (1<<24) + 5;
const int inf = 0x3f3f3f3f;

#define bit(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline int dist(int x1,int y1,int x2,int y2){ return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);}

int lb[ALL];

struct Node
{
	int x,y;
};

int n;
Node a[MAXN];
int dis[MAXN][MAXN];

int f[ALL],g[ALL];

vector<int> ans;

int main(void)
{
	scanf("%d%d%d",&a[0].x,&a[0].y,&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	
	for(int i=0; i<n; ++i) lb[1<<i]=i;
	
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=n; ++j)
			dis[i][j] = dist(a[i].x,a[i].y, a[j].x,a[j].y);
	
	int all = (1<<n)-1;
	
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int mask=0; mask<all; ++mask)
	{	
		int i = lb[lowbit(~mask)]+1;
		int next = mask|(1<<(i-1));
		
		if(f[next] > f[mask]+dis[0][i]*2)
		{
			f[next] = f[mask]+dis[0][i]*2;
			g[next] = mask;
		}
		for(int j=i+1; j<=n; ++j)
			if(!bit(mask,j-1))
			{
				int nextt = next|(1<<(j-1));
				if(f[nextt] > f[mask]+dis[0][i]+dis[i][j]+dis[j][0])
				{
					f[nextt] =  f[mask]+dis[0][i]+dis[i][j]+dis[j][0];
					g[nextt] = mask;
				}
			}
	}
	
	int now=all;
	while(now)
	{
		ans.push_back(0);
		int step = now^g[now];
		for(int i=1; i<=n; ++i)
			if(bit(step,i-1))
				ans.push_back(i);
		now=g[now];
	}
	ans.push_back(0);
	reverse(ans.begin(),ans.end());
	
	printf("%d\n",f[all]);
	for(uint i=0; i<ans.size(); ++i)
		printf("%d ",ans[i]);
	return 0;
}