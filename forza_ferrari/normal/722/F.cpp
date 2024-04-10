#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,len[100001],a[100001][41],ans[100001],maxn,l;
struct node
{
	int id,a,b;
}t[100001];
vector<node> v[100001];
int gcd(int x,int y)
{
	return x%y? gcd(y,x%y):y;
}
inline bool excrt(int x,int y,int a,int b)
{
	return x==a? y==b:(y-b)%gcd(x,a)==0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		maxn=max(maxn,k);
		for(register int j=1;j<=k;++j)
		{
			int x;
			scanf("%d",&x);
			node nw;
			nw.id=i;
			nw.a=k;
			nw.b=j-1;
			v[x].push_back(nw);
		}
	}
	for(register int i=1;i<=m;++i)
	{
		l=0;
		for(register int j=1;j<=maxn;++j)
			t[j].a=t[j].b=0;
		for(register int j=0;j<(int)v[i].size();++j)
		{
			if(i&&v[i][j].id!=v[i][j-1].id+1)
				while(l<j)
					--t[v[i][l++].a].a;
			for(register int k=1;k<=maxn;++k)
				if(t[k].a&&!excrt(k,t[k].b,v[i][j].a,v[i][j].b))
					while(t[k].a)
						--t[v[i][l++].a].a;
			++t[v[i][j].a].a;
			t[v[i][j].a].b=v[i][j].b;
			ans[i]=max(ans[i],j-l+1);
		}
	}
	for(register int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}