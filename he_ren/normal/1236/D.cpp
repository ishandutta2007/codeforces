#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXD = 1e5 + 5;

inline int min(int a,int b){ return a<b? a: b;}
inline int max(int a,int b){ return a>b? a: b;}
inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Node
{
	int x,y;
}a[MAXD];

vector<int> s[MAXN],t[MAXN];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=d; ++i) scanf("%d%d",&a[i].x,&a[i].y);
	
	for(int i=1; i<=d; ++i) s[a[i].y].push_back(a[i].x);
	for(int i=1; i<=m; ++i) s[i].push_back(0), s[i].push_back(n+1);
	for(int i=1; i<=m; ++i) sort(s[i].begin(), s[i].end());
	
	for(int i=1; i<=d; ++i) t[a[i].x].push_back(a[i].y);
	for(int i=1; i<=n; ++i) t[i].push_back(0), t[i].push_back(m+1);
	for(int i=1; i<=n; ++i) sort(t[i].begin(), t[i].end());
	
	int ux=n,dx=1, uy=m,dy=1, x=1,y=1,k=0;
	ll tot=1, lst;
	while(1)
	{
		int nx,ny;
		int i = lower_bound(s[y].begin(),s[y].end(),x) - s[y].begin();
		int j = lower_bound(t[x].begin(),t[x].end(),y) - t[x].begin();
		if(k==0)
		{
			nx = x;
			ny = min(t[x][j]-1, uy);
			dx = x+1;
			lst = ny-y;
		}
		if(k==2)
		{
			nx = x;
			ny = max(t[x][j-1]+1, dy);
			ux = x-1;
			lst = y-ny;
		}
		
		if(k==1)
		{
			ny = y;
			nx = min(s[y][i]-1, ux);
			uy = y-1;
			lst = nx-x;
		}
		if(k==3)
		{
			ny = y;
			nx = max(s[y][i-1]+1, dx);
			dy = y+1;
			lst = x-nx;
		}
		
		if(!lst && (tot>1 || k==1)) break;
		tot+=lst;
		
		x=nx; y=ny;
		++k;
		if(k>=4) k=0;
	}
	
	if(tot == (ll)n*m-d) printf("YES");
	else printf("NO");
	return 0;
}