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
#define maxN 1
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define oo 1000111222
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

int step,m,n,d[55][55],sm;
string a[55];
pair< pii , pii > b[2555];

pair <int,int> findNext(int x,int y,int z,int t,int i,int j,int I,int J)
{
	int rem=(z+t)%4;
	if (!rem) return mp(i,j);
	if (rem==1) return mp(i,J);
	if (rem==2) return mp(I,J);
	if (rem==3) return mp(I,j);
	return mp(x,y);
}

int main()
{
	cin >> m >> step;
	rep(i,m) cin >> a[i];
	n=sz(a[0]);
	rep(i,m) rep(j,n) 
		if (!d[i][j] && a[i][j]!='0')
		{
			int I=i,J=j;
			while (I<m && a[I][j]==a[i][j]) I++;
			while (J<n && a[i][J]==a[i][j]) J++;
			I--; J--;
			b[++sm]=mp(mp(i,j),mp(I,J));
			fr(ii,i,I) fr(jj,j,J) d[ii][jj]=sm;
		}
	int x=0,y=0,z=1,t=0;
	while (step--)
	{
		int c=d[x][y],i=b[c].fi.fi,j=b[c].fi.se,I=b[c].se.fi,J=b[c].se.se;
		pair <int,int> u=findNext(x,y,z,t,i,j,I,J);		
		x=u.fi; y=u.se;
		int xx=x+dx[z],yy=y+dy[z];
		if (xx>=0 && xx<m && yy>=0 && yy<n && a[xx][yy]!='0') x=xx, y=yy;
		else
		{
			if (t) z=(z+1)&3;
			t^=1;
		}
	}
	cout << a[x][y] << endl;
}