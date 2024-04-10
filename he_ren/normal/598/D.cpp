#include<cstdio>
#include<queue>
const int MAXN = 1e3 + 5;
const int MAXP = MAXN * MAXN;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
using namespace std;

char s[MAXN][MAXN];
int clr[MAXN][MAXN],ans[MAXP],ccnt=0;

struct Node
{
	int x,y;
};
queue<Node> q;

int main(void)
{
	int n,m,qry;
	scanf("%d%d%d",&n,&m,&qry);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	while(qry--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(clr[x][y])
		{
			printf("%d\n",ans[clr[x][y]]);
			continue;
		}
		clr[x][y]=++ccnt;
		
		q.push((Node){x,y});
		while(!q.empty())
		{
			int i=q.front().x, j=q.front().y;
			q.pop();
			for(int k=0; k<4; ++k)
			{
				int ni=i+dx[k], nj=j+dy[k];
				if(ni<1 || ni>n || nj<1 || nj>m || clr[ni][nj]) continue;
				
				if(s[ni][nj]=='*') ++ans[ccnt];
				else
				{
					q.push((Node){ni,nj});
					clr[ni][nj]=ccnt;
				}
			}
		}
		printf("%d\n",ans[ccnt]);
	}
	return 0;
}