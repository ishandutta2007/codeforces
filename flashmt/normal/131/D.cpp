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
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define oo 1000111222
using namespace std;

int n,x,y,found,d[3030],color[3030],onCycle[3030],tr[3030];
vector <int> a[3030];

void markCycle(int x,int y)
{
	onCycle[x]=1; 
	do
	{
		x=tr[x]; onCycle[x]=1;
	} while (x!=y);
}

void findCycle(int x,int par)
{
	tr[x]=par;
	color[x]=1;
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (y==par) continue;
		if (color[y]==1) 
		{
			found=1;
			markCycle(x,y);
			return;
		}
		else
			if (!color[y]) findCycle(y,x);
		if (found) return;
	}
	color[x]=2;
}

void visit(int x,int par)
{
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (y==par || onCycle[y]) continue;
		d[y]=d[x]+1;
		visit(y,x);
	}
}

int main()
{
	cin >> n;
	rep(i,n) cin >> x >> y, a[x].pb(y), a[y].pb(x);
	findCycle(1,0);
	fr(i,1,n)
		if (onCycle[i]) visit(i,0);
	fr(i,1,n) cout << d[i] << " ";
	puts("");
}