#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXL = 5e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Point
{
	int x,y;
};

const int MAXP = 1e3;
const int dx[] = {0,1,0,-1,1,-1};
const int dy[] = {1,0,-1,0,1,-1};
struct Paint_Board
{
	int a[MAXP][MAXP], clr[MAXP][MAXP], d[MAXP][MAXP], cnt;
	Paint_Board(void){ clear();}
	
	void clear(void){ cnt=0; memset(a,0,sizeof(a)); memset(clr,0,sizeof(clr)); memset(d,0,sizeof(d));}
	
	void print(int n = 30)
	{
		for(int j=n; j>=0; --j, putchar('\n'))
			for(int i=0; i<=n; ++i)
				printf(a[i][j]? "[]": "  ");
		printf("\n");
	}
	void print_cross(int n = 30)
	{
		for(int j=n; j>=0; --j, putchar('\n'))
			for(int i=0; i<=n; ++i)
				printf(a[i][j]==cnt? "[]": "  ");
		printf("\n");
	}
	void print_count(int n = 30)
	{
		printf("\n");
		for(int j=n; j>=0; --j, putchar('\n'))
			for(int i=0; i<=n; ++i)
			{
				if(a[i][j] == 0) printf("   ");
				else if(a[i][j] == 1)
				{
					printf(" %d ",clr[i][j]);
//					if(clr[i][j] == 1) printf(" = ");
//					else if(clr[i][j] == 2) printf(" # ");
//					else printf(" & ");
				}
				else printf("[%d]",a[i][j]);
			}
		printf("\n");
	}
	
	void paint(int x,int y,int dis){ ++cnt; dfs(x,y,dis);}
	void dfs(int x,int y,int dis)
	{
		if(clr[x][y] != cnt){ clr[x][y]=cnt; d[x][y]=0; ++a[x][y];}
		if(d[x][y] >= dis) return;
		d[x][y] = dis;
		
		--dis;
		for(int k=0; k<6; ++k)
		{
			int xx = x + dx[k], yy = y + dy[k];
			if(xx<0 || xx>=MAXP || yy<0 || yy>=MAXP) continue;
			dfs(xx,yy,dis);
		}
	}
	void paint(Point p,int dis){ paint(p.x,p.y,dis);}
}board;

int n;
Point p[MAXN];

pii check(int mid)
{
	int u=5e5, d=0, l=0, r=5e5, lu=5e6, rd=-5e6;
	for(int i=1; i<=n; ++i)
	{
		int x = p[i].x, y = p[i].y;
		chk_min(u, y + mid); chk_max(d, y - mid);
		chk_max(l, x - mid); chk_min(r, x + mid);
		chk_min(lu, y+mid - x); chk_max(rd, y-mid - x);
	}
	if(u<d || l>r || lu<rd) return make_pair(-1,-1);
	if(l+rd > u || r+lu < d) return make_pair(-1,-1);
	
	if(r + lu >= u && r + rd <= u) return make_pair(r,u);
	if(r + rd >= d) return r + rd <= u? make_pair(r, r + rd): make_pair(u - rd, u);
	if(l + lu <= u) return l + lu >= d? make_pair(l, l + lu): make_pair(d - lu, d);
	return make_pair(r,u);
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		static char s[MAXL];
		scanf("%s",s+1);
		for(int j=1; s[j]; ++j)
			if(s[j] == 'N') ++p[i].x;
			else ++p[i].y;
	}
	
//	board.clear();
//	for(int i=1; i<=n; ++i)
//		board.paint(p[i], 4);
//	board.print_count();
	
	int l=0, r=5e5;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(check(mid).first != -1) r=mid;
		else l=mid+1;
	}
	
	pii res = check(l);
	printf("%d\n",l);
	for(int i=1; i<=res.first; ++i) putchar('N');
	for(int i=1; i<=res.second; ++i) putchar('B');
	return 0;
}