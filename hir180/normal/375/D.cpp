//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//solution with using "Typical technique in merging data structure"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int n,m;
int col[100005],ret[100005];
vector<int>edge[100005];
vector<P>query[100005];
struct node
{
	map<int,int>ma;
	vector<int>v;
	int s;
	node()
	{
		s=0;
		ma.clear();
		v.clear();
		v.pb(-1);
	}
	void plus(int col)
	{
		s++;
		int rep=++ma[col];
		if(rep>=v.size())
		{
			v.pb(1);
		}
		else
		{
			v[rep]++;
		}
	}
	void merge(const node& n)
	{
		map<int,int>x=n.ma;
		for(map<int,int>::iterator it=x.begin();it!=x.end();++it)
		{
			for(int i=0;i<it->s;i++)
			{
				plus(it->f);
			}
		}
	}
};
//bring smaller group into larger group
//each element can't change its group more than (log n)
//because when element change its group, its group size increases twice.
//so, this algorithm runs O(n log n)
node* merge(node* a,node* b)
{
	if(a->s < b->s)
	{
		b->merge(*a);
		return b;
	}
	else
	{
		a->merge(*b);
		return a;
	}
}
node* dfs(int v,int u)
{
	node* now=new node;
	now->plus(col[v]);
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i]==u) continue;
		now=merge(now,dfs(edge[v][i],v));
	}
	for(int i=0;i<query[v].size();i++)
	{
		int least=query[v][i].f;
		int id=query[v][i].s;
		if(least<(now->v).size())
		{
			ret[id]=(now->v)[least];
		}
		else
		{
			ret[id]=0;
		}
	}
	return now;
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&col[i]);
	for(int i=0;i<n-1;i++)
	{
		int x,y; scanf("%d %d",&x,&y);
		x--; y--; edge[x].pb(y); edge[y].pb(x);
	}
	for(int i=0;i<m;i++)
	{
		int v,val; scanf("%d%d",&v,&val);
		query[v-1].pb(mp(val,i));
	}
	dfs(0,-1);
	for(int i=0;i<m;i++) printf("%d\n",ret[i]);
}