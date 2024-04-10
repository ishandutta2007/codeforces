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

int n,posVertex[100100],posEdge[100100],B,branchEdge[100100],branchVertex[100100],cnt[100100];
vector <int> a[100100],f[100100];
vector < pair<int,int> > edge;

void visit(int i,int x)
{
	branchEdge[i]=branchVertex[x]=B;
	posEdge[i]=posVertex[x]=++cnt[B];
	rep(j,sz(a[x]))
	{
		int k=a[x][j],y=(edge[k].fi==x?edge[k].se:edge[k].fi);
		if (k==i) continue;
		visit(k,y);
	}
}

void add(int B,int x,int v)
{
	while (x<=cnt[B])
	{
		f[B][x]+=v;
		x+=x&-x;
	}
}

int get(int B,int x)
{
	if (!B) return 0;
	int res=0;
	while (x)
	{
		res+=f[B][x];
		x-=x&-x;
	}
	return res;
}

int main()
{
	cin >> n;
	rep(i,n-1)
	{
		int x,y;
		cin >> x >> y;
		edge.pb(mp(x,y));
		a[x].pb(i); a[y].pb(i);
	}
	
	int root=1;
	rep(i,n)
		if (sz(a[i])>2) root=i;
		
	rep(i,sz(a[root]))
	{
		int j=a[root][i],y=(edge[j].fi==root?edge[j].se:edge[j].fi);
		B++;
		visit(j,y);
		f[B].resize(cnt[B]+1);
	}
	
	int q;
	cin >> q;
	while (q--)
	{
		int type,x,y;
		scanf("%d%d",&type,&x);
		
		if (type==1) add(branchEdge[x-1],posEdge[x-1],-1);
		
		if (type==2) add(branchEdge[x-1],posEdge[x-1],1);
		
		if (type==3)
		{
			scanf("%d",&y);
			int X=get(branchVertex[x],posVertex[x]);
			int Y=get(branchVertex[y],posVertex[y]);
			
			if (x==root) cout << (!Y?posVertex[y]:-1);
			else
				if (y==root) cout << (!X?posVertex[x]:-1);
				else
					if (branchVertex[x]==branchVertex[y]) 
						cout << (X==Y?abs(posVertex[x]-posVertex[y]):-1);
					else cout << (!X && !Y?posVertex[x]+posVertex[y]:-1);
			puts("");
		}
	}
}