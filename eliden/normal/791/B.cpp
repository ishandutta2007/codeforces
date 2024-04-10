#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int sz = 1e6;

int par[sz];
ll edges[sz];
int root(int i)
{
	if(par[i]>=0)
		return par[i] = root(par[i]);
	return i;
}
void merge(int x, int y)
{
	x = root(x), y= root(y);
	if(x==y)
		return;
	if(par[y]<par[x])
		swap(x,y);
	par[x]+=par[y];
	par[y]=x;
	edges[x]+=edges[y];
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n)
	{
		par[i]=-1;
		edges[i]=0;
	}
	rep(i,0,m)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		--a, --b;
		merge(a,b);
		++edges[root(a)];
	}
	bool good=true;
	rep(i,0,n)
		if(par[i]<0)
		{
			ll csize = -par[i];
			if(csize*(csize-1)!=2*edges[i])
				good=false;
		}
	if(good)
		printf("YES\n");
	else
		printf("NO\n");
	
}