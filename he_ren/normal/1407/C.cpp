#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;

int ask(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	static int p[MAXN];
	for(int i=1; i<=n; ++i) p[i] = 0;
	
	int pos = 1;
	for(int i=2; i<=n; ++i)
	{
		int xy = ask(pos,i);
		int yx = ask(i,pos);
		if(yx > xy) p[i] = yx;
		else
		{
			p[pos] = xy;
			pos = i;
		}
	}
	
	bool vis[MAXN];
	for(int i=1; i<=n; ++i) vis[i] = 0;
	for(int i=1; i<=n; ++i)
		vis[p[i]] = 1;
	for(int i=1; i<=n; ++i)
		if(!vis[i])
		{
			p[pos] = i;
			break;
		}
	printf("! ");
	for(int i=1; i<=n; ++i) printf("%d ",p[i]);
	putchar('\n');
	fflush(stdout);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}