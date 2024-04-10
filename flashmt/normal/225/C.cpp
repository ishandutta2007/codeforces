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

int c[1010],m,n,x,y,f[1010][1010],g[1010][1010];

int main()
{
	cin >> m >> n >> x >> y;
	y=min(y,n); 
	fr(i,1,m)
	{
		string s;
		cin >> s;
		fr(j,1,n) c[j]+=(s[j-1]=='#');
	}
	
	fr(i,0,n) fr(j,0,n) f[i][j]=g[i][j]=oo;
	f[1][1]=c[1];
	g[1][1]=m-c[1];
	
	fr(i,2,n)
		fr(j,1,y)
		{
			if (f[i-1][j]!=oo)
			{
				if (j>=x) g[i][1]=min(g[i][1],f[i-1][j]+m-c[i]);
				if (j<y) f[i][j+1]=min(f[i][j+1],f[i-1][j]+c[i]);
			}
			if (g[i-1][j]!=oo)
			{
				if (j>=x) f[i][1]=min(f[i][1],g[i-1][j]+c[i]);
				if (j<y) g[i][j+1]=min(g[i][j+1],g[i-1][j]+m-c[i]);
			}
		}
			
	int ans=oo;
	fr(j,x,y) ans=min(ans,min(f[n][j],g[n][j]));
	cout << ans << endl;
}