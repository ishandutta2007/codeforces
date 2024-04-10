#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

char s[MAXN][MAXM];
int f[MAXN][MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	
	queue<pii> q;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			bool flag = 1;
			for(int k=0; k<4; ++k)
			{
				int x = i+dx[k];
				int y = j+dy[k];
				if(x<1||x>n||y<1||y>m){ flag=0; break;}
				if(s[x][y]!=s[i][j]){ flag=0; break;}
			}
			if(!flag) f[i][j]=1, q.push(make_pair(i,j));
		}
	
	while(!q.empty())
	{
		int x=q.front().first, y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; ++k)
		{
			int xx=x+dx[k], yy=y+dy[k];
			if(xx<1||xx>n||yy<1||yy>m||f[xx][yy]) continue;
			f[xx][yy] = f[x][y] + 1;
			q.push(make_pair(xx,yy));
		}
	}
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			ans += f[i][j];
	printf("%lld",ans);
	return 0;
}