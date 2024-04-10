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

int n,m,ans,f[333][333][10],F[333][333],g[333][333];

int main()
{
	cin >> n >> m;
	fr(i,1,n)	fr(j,1,n) fr(k,0,10) f[i][j][k]=-oo;
	fr(i,1,n) f[i][i][0]=0;
	while (m--)
	{
		int x,y,u,v;
		scanf("%d%d%d%d",&x,&y,&u,&v);
		f[x][y][0]=max(f[x][y][0],u);
		f[y][x][0]=max(f[y][x][0],v);
	}
	fr(k,0,7)
		fr(p,1,n)
			fr(i,1,n)
				fr(j,1,n)
					f[i][p][k+1]=max(f[i][p][k+1],f[i][j][k]+f[j][p][k]);
	fr(i,1,n) fr(j,1,n) F[i][j]=(i-j?-oo:0);
	frr(k,8,0)
	{
		fr(i,1,n) fr(j,1,n) g[i][j]=-oo;
		fr(p,1,n)
			fr(i,1,n)
				fr(j,1,n)
					g[i][j]=max(g[i][j],F[i][p]+f[p][j][k]);
		int ok=0;
		fr(i,1,n)	
			if (g[i][i]>0) ok=1;
		if (!ok) 
		{
			ans+=1<<k;
			fr(i,1,n) fr(j,1,n) F[i][j]=g[i][j];
		}
	}
	cout << (ans>n?0:ans+1) << endl;
}