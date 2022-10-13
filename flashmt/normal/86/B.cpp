#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<utility>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};
      
int n,m,r[1111][1111],d[10];
char a[1111][1111];
vector < pii > b;

int Count(int x,int y)
{
	int i,xx,yy;
	fr(i,0,3)
	{
		xx=x+dx[i]; yy=y+dy[i];
		if (xx && yy && xx<=m && yy<=n && a[xx][yy]=='.' && r[xx][yy]==-1) return 1;
	}
	return 0;
}

void fill(int x,int y,int c)
{
	int i,xx,yy;
	fr(i,0,3)
	{
		xx=x+dx[i]; yy=y+dy[i];
		if (xx && yy && xx<=m && yy<=n && a[xx][yy]=='.' && r[xx][yy]==-1 && !Count(xx,yy)) 
			b.pb(mp(xx,yy));
	}
}
      
void visit(int x,int y)
{
	int i,j,xx,yy,X=0,Y;
	b.clear();
	fr(i,0,9) d[i]=0;
	fr(i,0,3)
	{
		xx=x+dx[i]; yy=y+dy[i];
		if (xx && yy && xx<=m && yy<=n && a[xx][yy]=='.' && r[xx][yy]==-1) X=xx, Y=yy;
	}
	if (!X)
	{
		cout << -1 << endl;
		exit(0);
	}
	b.pb(mp(x,y));
	b.pb(mp(X,Y));
	r[x][y]=r[X][Y]=-2;
	fill(x,y,i);
	fill(X,Y,i);	
	fr(j,0,b.size()-1)
	{
		x=b[j].F; y=b[j].S;
		fr(i,0,3)
		{
			xx=x+dx[i]; yy=y+dy[i];
			if (xx && yy && xx<=m && yy<=n && r[xx][yy]>=0) d[r[xx][yy]]=1;
		}
	}
	fr(i,0,9)
		if (!d[i]) break;
	fr(j,0,b.size()-1) r[b[j].F][b[j].S]=i;
}

int main()
{
	int i,j;
	cin >> m >> n;
	fr(i,1,m) scanf("%s",&a[i]);
	fr(i,1,m) frr(j,n,1) a[i][j]=a[i][j-1], r[i][j]=-1;
	fr(i,1,m)
		fr(j,1,n)
			if (r[i][j]<0 && a[i][j]=='.')
				visit(i,j);
	fr(i,1,m)
	{
		fr(j,1,n)
			if (r[i][j]>=0) printf("%d",r[i][j]);
			else printf("#");
		printf("\n");
	}
  return 0;
}