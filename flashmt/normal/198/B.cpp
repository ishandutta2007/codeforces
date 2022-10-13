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

int n,k,f[2][100100],d[2][100100];
string a[2];
priority_queue < pair<int,pii > > q;

int main()
{
	cin >> n >> k >> a[0] >> a[1];
	rep(i,2) rep(j,n) f[i][j]=oo;
	f[0][0]=0; q.push(mp(0,mp(0,0)));
	
	while (!q.empty())
	{
		pair <int,pii > u=q.top(); q.pop();
		int F=-u.fi,i=u.se.fi,j=u.se.se;
		if (F!=f[i][j] || F>j) continue;
		if (j+k>=n)
		{
			puts("YES"); return 0;
		}
		d[i][j]=1;
		
		if (j+1<n && a[i][j+1]=='-' && !d[i][j+1] && f[i][j+1]>F+1)
		{
			f[i][j+1]=F+1;
			q.push(mp(-F-1,mp(i,j+1)));
		}
		
		if (j-1>=0 && a[i][j-1]=='-' && !d[i][j-1] && f[i][j-1]>F+1)
		{
			f[i][j-1]=F+1;
			q.push(mp(-F-1,mp(i,j-1)));
		}
		
		if (a[i^1][j+k]=='-' && !d[i^1][j+k] && f[i^1][j+k]>F+1)
		{
			f[i^1][j+k]=F+1;
			q.push(mp(-F-1,mp(i^1,j+k)));
		}
	}
	puts("NO");
}