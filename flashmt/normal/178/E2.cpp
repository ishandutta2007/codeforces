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
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define sqr(x) ((x)*(x))
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

int n,a[2020][2020],square,circle,d[2020][2020],qx[4000400],qy[4000400],q;

double dist(double x,double y,double xx,double yy)
{
	return sqrt(sqr(x-xx)+sqr(y-yy));
}

int isSquare(int x,int y)
{
	int maxX=x,minX=x,maxY=y,minY=y,cur=1,X=x,Y=y;
	d[x][y]=q=1;
	qx[1]=x; qy[1]=y;
	while (cur<=q)
	{
		x=qx[cur]; y=qy[cur++];
		rep(i,4)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if (xx && yy && xx<=n && yy<=n && a[xx][yy] && !d[xx][yy])
			{
				d[xx][yy]=1; 
				qx[++q]=xx; qy[q]=yy;
				X+=xx; Y+=yy;
				minX=min(minX,xx); maxX=max(maxX,xx);
				minY=min(minY,yy); maxY=max(maxY,yy);
			}
		}
	}
	if (q==(maxX-minX+1)*(maxY-minY+1)) return 1;
		
	double cx=1.0*X/q,cy=1.0*Y/q;
	int border=1;
	vector <double> D;
	fr(i,1,q) D.pb(-dist(cx,cy,qx[i],qy[i]));
	sort(all(D));
	fr(i,1,sz(D)-1)
		if (fabs(D[i]-D[0])<2) border++;
		else break;
	return border<100;
}

int main()
{
	cin >> n;
	fr(i,1,n)
		fr(j,1,n)
			scanf("%d",&a[i][j]);
	
	fr(i,1,n)
		fr(j,1,n)
			if (a[i][j] && !d[i][j])
				if (isSquare(i,j)) square++;
				else circle++;
				
	cout << circle << ' ' << square << endl;
}