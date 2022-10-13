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
#define maxN 1
using namespace std;

int m,n,f[1111][1111][2];
string a[1111];
queue <int> qx,qy,qz;

void push(int x,int y,int z)
{
	qx.push(x);
	qy.push(y);
	qz.push(z);
}

void pop(int &x,int &y,int &z)
{
	x=qx.front(); qx.pop();
	y=qy.front(); qy.pop();
	z=qz.front(); qz.pop();
}

int main()
{
	cin >> m >> n;
	rep(i,m) cin >> a[i];
	reset(f,-1);
	rep(j,n)
		if (a[m-1][j]=='#') f[m-1][j][0]=0, push(m-1,j,0);
	while (!qx.empty())
	{
		int x,y,z;
		pop(x,y,z);
		if (f[x][y][1-z]<0 || f[x][y][1-z]>f[x][y][z]+1) f[x][y][1-z]=f[x][y][z]+1;
		
		frr(i,x-1,0)
			if (a[i][y]=='#')
			{
				if (f[i][y][1]<0 || f[i][y][1]>f[x][y][1])
					f[i][y][1]=f[x][y][1], push(i,y,1);
				break;
			}
			
		fr(i,x+1,m-1)
			if (a[i][y]=='#')
			{
				if (f[i][y][1]<0 || f[i][y][1]>f[x][y][1])
					f[i][y][1]=f[x][y][1], push(i,y,1);
				break;
			}
			
		frr(j,y-1,0)
			if (a[x][j]=='#')
			{
				if (f[x][j][0]<0 || f[x][j][0]>f[x][y][0])
					f[x][j][0]=f[x][y][0], push(x,j,0);
				break;
			}
		fr(j,y+1,n-1)
			if (a[x][j]=='#')
			{
				if (f[x][j][0]<0 || f[x][j][0]>f[x][y][0])
					f[x][j][0]=f[x][y][0], push(x,j,0);
				break;
			}
	}
	int ans=oo;
	rep(j,n) 
		if (f[0][j][0]>=0) ans=min(ans,f[0][j][0]);
	if (ans==oo) ans=-1;
	cout << ans << endl;
}