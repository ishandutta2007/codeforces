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
#define oo 1000111222
using namespace std;
const int dx[]={-1,-1,0,1,1,1,0,-1,0};
const int dy[]={0,1,1,1,0,-1,-1,-1,0};

int n,d[8][8][10];
string a[8];

int ok(int x,int y,int t)
{
	if (x+t<8 && a[x+t][y]=='S') return 0;
	if (x+t+1<8 && a[x+t+1][y]=='S') return 0;
	return 1;
}

void go(int x,int y,int t)
{
	d[x][y][t]=1;
	if (x+y==14 || t>8) 
	{
		puts("WIN");
		exit(0);
	}
	rep(i,9) rep(j,9)
	{
		int xx=x+dx[i], yy=y+dy[i];
		if (xx>=0 && yy>=0 && xx<8 && yy<8 && !d[xx][yy][t+1] && ok(xx,yy,t))	go(xx,yy,t+1);
	}
}

int main()
{
	repp(i,8) cin >> a[i];
	go(0,0,0);
	puts("LOSE");
}