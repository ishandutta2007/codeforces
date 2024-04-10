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

int n,h[100100],p[100100][20],H,d[100100],ans[100100];
vector <int> a[100100],c[100100];

void visit(int x,int par)
{
	p[x][0]=par;
	H=max(H,h[x]);
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (y==par) continue;
		h[y]=h[x]+1;
		visit(y,x);
	}
}

int lca(int x,int y)
{
	if (h[x]<h[y]) swap(x,y);
	int lg=0;
	while (1<<lg<h[x]) lg++;
	frr(i,lg,0)
		if (h[x]-(1<<i)>=h[y])
			x=p[x][i];
	
	if (x==y) return x;
	
	frr(i,lg,0)
		if (p[x][i]!=p[y][i])
			x=p[x][i], y=p[y][i];
	
	return p[x][0];
}

int calc(int x,int id)
{
	int s=0;
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (y==p[x][0]) continue;
		s+=calc(y,c[x][i]);
	}
	return ans[id]=s+d[x];
}

int main()
{
	int x,y;
	cin >> n;
	rep(i,n-1) cin >> x >> y, a[x].pb(y), a[y].pb(x), c[x].pb(i), c[y].pb(i);
	visit(1,0);
	
	fr(j,1,19)
		fr(i,1,n)
			p[i][j]=p[p[i][j-1]][j-1];
	
	int q;
	cin >> q;
	while (q--)
	{
		cin >> x >> y;
		int z=lca(x,y);
		d[x]++; d[y]++;
		d[z]-=2;
	}
	
	calc(1,100000);
	rep(i,n-1) cout << ans[i] << ' ';
}