#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;
const int maxp = 5e5;
const int MAXP = maxp + 5;
const int LB = 20 + 5;
const int inf = 0x3f3f3f3f;

int lb[MAXN];

struct Seg
{
	int l,r;
}p[MAXN];

int to[MAXP][LB];

inline int calc(int pos,int k)
{
	for(int i=0; i<=lb[k]; ++i)
		if(k & (1<<i)) pos = to[pos][i];
	return pos;
}

int main(void)
{
	lb[1] = 0;
	for(int i=1; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].l,&p[i].r);
	
	for(int i=0; i<=maxp; ++i) to[i][0] = -inf;
	for(int i=1; i<=n; ++i)
		to[p[i].l][0] = max(to[p[i].l][0], p[i].r);
	for(int i=0; i<=maxp; ++i)
		to[i][0] = max(to[i][0], to[i-1][0]);
	
	for(int i=maxp; i>=0; --i)
	{
		if(to[i][0] < i) to[i][0] = -inf;
		else
		{
			for(int j=1; j<=lb[n]; ++j)
				to[i][j] = to[to[i][j-1]][j-1];
		}
	}
	
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(to[x][0]<x || calc(x,n) < y){ printf("-1\n"); continue;}
		
		int ans = 0;
		for(int k=lb[n], nxt; k>=0; --k)
			if((nxt = to[x][k]) < y)
				ans += (1<<k),
				x = nxt;
		++ans;
		printf("%d\n",ans);
	}
	return 0;
}