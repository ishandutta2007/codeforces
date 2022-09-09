#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 1e5 + 5;

int a[4][MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	int cnt=0;
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int xx=2/x;
		if(a[x][y])
		{
			if(a[xx][y]) --cnt;
			if(a[xx][y-1]) --cnt;
			if(a[xx][y+1]) --cnt;
		}
		else
		{
			if(a[xx][y]) ++cnt;
			if(a[xx][y-1]) ++cnt;
			if(a[xx][y+1]) ++cnt;
		}
		a[x][y]=!a[x][y];
		if(!cnt) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}