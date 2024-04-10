#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
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

int n,m,re,cnt;
vector <int> a[5050],d[5050],next[5][5050],cur[5][5050];

void init()
{
	int i,j,k;
	fr(i,0,m-1)
		fr(j,0,n-1)
		{
			fr(k,i+1,m-1)
				if (a[k][j]) break;
			next[4][i][j]=k;
			frr(k,i-1,0)
				if (a[k][j]) break;
			next[1][i][j]=k;
			fr(k,j+1,n-1)
				if (a[i][k]) break;
			next[2][i][j]=k;
			frr(k,j-1,0)
				if (a[i][k]) break;
			next[3][i][j]=k;
		}
}

int ok(int x,int y)
{
	return x>=0 && y>=0 && x<m && y<n;
}

void att(int x,int y)
{
	int i,j,k,point=0;
	fr(i,0,m-1) fr(j,0,n-1) fr(k,1,4) cur[k][i][j]=next[k][i][j];
	
	while (ok(x,y))
	{
		point++;
		k=a[x][y];
		int ux=cur[1][x][y],dx=cur[4][x][y];
		int ly=cur[3][x][y],ry=cur[2][x][y];
		if (ok(x,ly)) cur[2][x][ly]=ry; 
		if (ok(x,ry)) cur[3][x][ry]=ly;
		if (ok(ux,y)) cur[4][ux][y]=dx; 
		if (ok(dx,y)) cur[1][dx][y]=ux;
		if (k==1 || k==4) x=(k==1?ux:dx);
		else y=(k==2?ry:ly);
	}
	
	if (point>re) re=point, cnt=1;
	else if (point==re) cnt++;
}

int main()
{
	//freopen("c.in.2","r",stdin);
	int i,j,k;
	char c;
	scanf("%d%d\n",&m,&n);
	fr(i,0,m-1)
	{
		fr(j,0,n-1) 
		{
			scanf("%c",&c);
			if (c=='U') a[i].push_back(1);
			if (c=='R') a[i].push_back(2);
			if (c=='L') a[i].push_back(3);
			if (c=='D') a[i].push_back(4);
			if (c=='.') a[i].push_back(0);
			d[i].push_back(0);
			fr(k,0,4) next[k][i].push_back(0), cur[k][i].push_back(0);
		}
		scanf("\n");
	}
	init();
	fr(i,0,m-1)
		fr(j,0,n-1)
			if (a[i][j]) att(i,j);
	cout << re << " " << cnt << endl;
	return 0;
}