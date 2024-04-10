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

int par[100100],n,depth[100100],ans[100100],lab[100100],cnt[100100];
vector <int> a[100100];
vector < pair<int,int> > q[100100];
string name[100100];
set < pair<int,string> > s[100100];

void dfs(int x)
{
	int mx=0;
	lab[x]=x;
	
	cnt[x]=1;
	rep(i,sz(a[x])) 
	{
		int y=a[x][i]; 
		depth[y]=depth[x]+1;
		dfs(y);
		cnt[x]+=cnt[y];
		if (cnt[y]>mx) lab[x]=lab[y], mx=cnt[y];
	}
}

void visit(int x)
{
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (lab[y]==lab[x]) visit(y);
	}
	
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (lab[y]==lab[x]) continue;
		visit(y);
		
		for (set < pair<int,string> >::iterator it=s[lab[y]].begin();it!=s[lab[y]].end();)
		{
			set < pair<int,string> >::iterator tmp=it++;
			s[lab[x]].insert(*tmp);
			s[lab[y]].erase(tmp);
		}
	}
	
	s[lab[x]].insert(mp(depth[x],name[x]));
	
	if (q[x].empty()) return;
	
	sort(all(q[x]));
	int j=0,k=depth[x]+q[x][0].fi,id=q[x][0].se;
	set < pair<int,string> >::iterator it=s[lab[x]].lower_bound(mp(k,""));
	
	while (it!=s[lab[x]].end())
	{
		if (it->fi==k) ans[id]++, it++;
		else 
			if (it->fi<k) it=s[lab[x]].lower_bound(mp(k,""));
			else
			{
				j=lower_bound(all(q[x]),mp(it->fi-depth[x],-1))-q[x].begin();
				if (j==sz(q[x])) break;
				k=depth[x]+q[x][j].fi;
				id=q[x][j].se;
			}
	}
	
	rep(i,sz(q[x])-1)
		if (q[x][i].fi==q[x][i+1].fi)
			ans[q[x][i+1].se]=ans[q[x][i].se];
}

int main()
{
	//freopen("e.in","r",stdin);
	int Q,x,k;
	cin >> n;
	fr(i,1,n) 
	{
		cin >> name[i] >> par[i];
		a[par[i]].push_back(i);
	}
	
	cin >> Q;
	rep(i,Q) cin >> x >> k, q[x].pb(mp(k,i));
	
	dfs(0);
	visit(0);
	
	rep(i,Q) cout << ans[i] << endl;
}