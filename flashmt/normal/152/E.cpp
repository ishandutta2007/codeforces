#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

class point
{
	public:
		int x,y,z,f;
		point(int _x,int _y,int _z,int _f)
		{
			x=_x; y=_y; z=_z; f=_f;
		}
};

struct comparison
{
	bool operator() (const point &x,const point &y) 
	{
		if (x.f<y.f) return 1;
		if (x.f==y.f && (x.x!=y.x || x.y!=y.y || x.z !=y.z)) return 1;
		return 0;
	}	
};

int n,m,k,a[111][111],id[111][111],f[111][111][1<<7],d[111][111];
set<point,comparison> s;
set<point,comparison>::iterator it;

void trace(int x,int y,int z)
{
	d[x][y]=1;
	if (f[x][y][z]==a[x][y]) return;
	
	fr(z1,0,z)
		if (f[x][y][z1]!=oo)
			rep(z2,1<<k)
				if ((z1|z2)==z)
				{
					if (z1<z && z2<z && f[x][y][z2]!=oo && f[x][y][z]==f[x][y][z1]+f[x][y][z2]-a[x][y])
					{
						trace(x,y,z1);
						trace(x,y,z2);
						return;
					}
					
					rep(t,4)
					{
						int xx=x+dx[t],yy=y+dy[t];
						if (!xx || !yy || xx>m || yy>n) continue;
						if (f[xx][yy][z2]!=oo && f[x][y][z]==f[x][y][z1]+f[xx][yy][z2])
						{
							if (z1<z) trace(x,y,z1);
							trace(xx,yy,z2);
							return;
						}
					}					
				}
} 

int dijkstra()
{
	while (!s.empty())
	{
		it=s.begin(); s.erase(it);
		int x=it->x,y=it->y,z=it->z,F=it->f;
		if (F!=f[x][y][z]) continue;
		
		if (z+1==1<<k) 
		{
			trace(x,y,z);
			return F;	
		}
		
		rep(zz,1<<k)
		{
			int Z=z|zz;
			if (f[x][y][Z]>f[x][y][z]+f[x][y][zz]-a[x][y])
			{
				f[x][y][Z]=f[x][y][z]+f[x][y][zz]-a[x][y];
				point u(x,y,Z,f[x][y][Z]);
				s.insert(u);
			}
		}
		
		rep(t,4)
		{
			int xx=x+dx[t],yy=y+dy[t];
			if (!xx || !yy || xx>m || yy>n) continue;
			rep(zz,1<<k)
			{
				int Z=z|zz;
				if (f[xx][yy][Z]>f[x][y][z]+f[xx][yy][zz])
				{
					f[xx][yy][Z]=f[x][y][z]+f[xx][yy][zz];
					point u(xx,yy,Z,f[xx][yy][Z]);
					s.insert(u);
				}
			}
		}
	} 
	return -1;
}

int main()
{
	int x,y;
	cin >> m >> n >> k;
	fr(i,1,m) fr(j,1,n) cin >> a[i][j];
	fr(i,1,k) cin >> x >> y, id[x][y]=i; 

	fr(i,1,m) fr(j,1,n) rep(z,1<<k) f[i][j][z]=oo;
	fr(x,1,m) fr(y,1,n)
	{
		int z=(id[x][y]?1<<(id[x][y]-1):0);
		f[x][y][z]=a[x][y];
		point u(x,y,z,a[x][y]);
		s.insert(u);
	}
	
	cout << dijkstra() << endl;	
	fr(i,1,m) 
	{
		fr(j,1,n) cout << (d[i][j]?'X':'.');
		puts("");
	}
}