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
#include <cassert>
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
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define maxN 1
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
const int oo = 1<<29;

string a[111];
int n,m,k,f[40][111][111],jx[40],jy[40],flag[111][111];
pii tr[40][111][111];
char d[40][111][111];

int timeNeed(char c)
{
	if (c>='0' && c<='9') return c-'0';
	return 1;
}

void visit(int z,int x,int y)
{
	fr(i,1,m) fr(j,1,n) f[z][i][j]=oo;
	f[z][x][y]=0; d[z][x][y]=1;
	
	while (1)
	{
		if (!f[z][x][y] || a[x][y]<'a')
			rep(i,4)
			{
				int xx=x+dx[i],yy=y+dy[i],t=timeNeed(a[x][y])+f[z][x][y];
				if (xx<=0 || xx>m || yy<=0 || yy>n || a[xx][yy]=='#' || d[z][xx][yy]) continue;
				if (f[z][xx][yy]>t)
					f[z][xx][yy]=t, tr[z][xx][yy]=mp(x,y);
			}
		
		int rx=0,ry,best=oo-1;
		fr(i,1,m)
			fr(j,1,n)
				if (!d[z][i][j] && f[z][i][j]<best)
					best=f[z][i][j], rx=i, ry=j;
		if (!rx) break;
		x=rx; y=ry; 
		d[z][x][y]=1;
	}
}

void find(int x,int y,int z,int k)
{
	vector < pii > path;
	
	while (jx[z]!=x || jy[z]!=y)
	{
		path.pb(mp(x,y));
		pair <int,int> u=tr[z][x][y];
		x=u.fi; y=u.se;
	}
	path.pb(mp(jx[z],jy[z]));
	
	repp(i,sz(path))
	{
		int x=path[i].fi,y=path[i].se;
		
		k-=timeNeed(a[x][y]);
		if (k<0) 
		{
			cout << x << ' ' << y << endl;
			exit(0);
		}
	}
}

int main()
{
	//freopen("f.in","r",stdin);
	int sx,sy,fx,fy;
	string s;
	
	cin >> m >> n >> k;
	fr(i,1,m) cin >> a[i], a[i]="$"+a[i];
	cin >> sx >> sy >> s >> fx >> fy;
	
	fr(i,1,m)
		fr(j,1,n)
			if (a[i][j]>='a' && a[i][j]<='z')
			{
				jx[a[i][j]-'a']=i;
				jy[a[i][j]-'a']=j;
				visit(a[i][j]-'a',i,j);
			}
			
	jx[26]=sx; jy[26]=sy;
	visit(26,sx,sy);
			
	int z=26,x,y,zz;
	rep(i,sz(s))
	{
		zz=s[i]-'a',x=jx[zz],y=jy[zz];
		if (k>f[z][x][y]) k-=f[z][x][y];
		else find(x,y,z,k);
		z=zz;
	}
	
	assert(k>0);
	if (k>=f[z][fx][fy]) cout << fx << ' ' << fy << endl;
	else find(fx,fy,z,k);
}