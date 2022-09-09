#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
#define Fir first
#define Sec second
const int MAXN = 2e5 + 5;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int t[5];

int main(void)
{
	int n,sx,sy;
	scanf("%d%d%d",&n,&sx,&sy);
	
	for(int i=1; i<=n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>sx) ++t[0];
		if(y>sy) ++t[1];
		if(x<sx) ++t[2];
		if(y<sy) ++t[3];
	}
	
	int mx=0;
	for(int i=1; i<=3; ++i)
		if(t[i]>t[mx]) mx=i;
	
	sx+=dx[mx]; sy+=dy[mx];
	printf("%d\n%d %d",t[mx],sx,sy);
	return 0;
}