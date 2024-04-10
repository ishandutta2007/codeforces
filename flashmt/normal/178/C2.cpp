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

int n,m,h,id[200200],pos[200200],region,cnt[200200];
map <int,int> val,where;

struct SegmentTree
{
	int* f;
	int n;
	
	void load(int _n)
	{
		n=_n; 
		f=new int[n*10];
		for (int i=0;i<n*10;i++) f[i]=0;
	}
	
	void update(int nd,int l,int r,int x,int v)
	{
		f[nd]+=v;
		if (l==r) return;
		int m=(l+r)/2;
		if (x<=m) update(nd*2,l,m,x,v);
		else update(nd*2+1,m+1,r,x,v);
	}
	
	int get(int nd,int l,int r,int x,int y)
	{
		if (l==x && r==y)
		{
			if (l==r) return (f[nd]?0:l);
			int m=(l+r)/2;
			if (f[nd*2]<m-l+1) return get(nd*2,l,m,l,m);
			return get(nd*2+1,m+1,r,m+1,r);
		}
		int t=0,m=(l+r)/2;
		if (x<=m) t=get(nd*2,l,m,x,min(y,m));
		if (t) return t;
		return get(nd*2+1,m+1,r,max(x,m+1),y);
	}
} tree[200200];

void visit(int x)
{
	cnt[++region]=1;
	id[x]=cnt[region]; pos[x]=region;
	while (1)
	{
		x=(x+m)%h;
		if (pos[x]) break;
		id[x]=++cnt[region]; pos[x]=region;
	}
	tree[region].load(cnt[region]);
}

int main()
{
	cin >> h >> m >> n;
	rep(i,h)
		if (!pos[i]) visit(i);
		
	long long ans=0;
	while (n--)
	{
		char s[10];
		int v,x;
		scanf("%s%d",s,&v);
		if (s[0]=='+')
		{
			scanf("%d",&x);
			int curReg=pos[x],N=cnt[curReg];
			int target=tree[curReg].get(1,1,N*2,id[x],id[x]+N-1);
			ans+=target-id[x];
			val[v]=target; where[v]=curReg;
			tree[curReg].update(1,1,N*2,target,1);
			int other=(target<=N?target+N:target-N);
			tree[curReg].update(1,1,N*2,other,1);
		}
		else
		{
			int target=val[v],curReg=where[v],N=cnt[curReg];
			int other=(target<=N?target+N:target-N);
			tree[curReg].update(1,1,N*2,target,-1);
			tree[curReg].update(1,1,N*2,other,-1);
		}
	}
	
	cout << ans << endl;
}