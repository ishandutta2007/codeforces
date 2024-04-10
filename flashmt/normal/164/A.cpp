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

int n,m,f[100100],g[100100],h[100100];
vector <int> a[100100],b[100100];

void visit(int x)
{
	g[x]=1;
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (f[y]!=1 && !g[y]) visit(y);
	}
}

void visit2(int x)
{
	h[x]=1;
	if (f[x]==1) return;
	rep(i,sz(b[x]))
	{
		int y=b[x][i];
		if (!h[y]) visit2(y);
	}
}

int main()
{
	int x,y;
	cin >> n >> m;
	fr(i,1,n) cin >> f[i];
	while (m--) cin >> x >> y, a[x].pb(y), b[y].pb(x);
	
	fr(i,1,n)
		if (f[i]==1) visit(i);
	
	fr(i,1,n)
		if (f[i]==2) visit2(i);
		
	fr(i,1,n) cout << (h[i]&g[i]?1:0) << endl;
}