#include<bits/stdc++.h>
using namespace std;
int n,ans;
namespace sp
{
	const int N=500005;
	int ch[N][2],fa[N],v[N],t[N],sz,rt;
	inline int lson(int x){return ch[fa[x]][1]==x;}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y];
		int l=lson(x),r=l^1;
		if(z) ch[z][lson(y)]=x;
		fa[x]=z,fa[y]=x,fa[ch[x][r]]=y;
		ch[y][l]=ch[x][r],ch[x][r]=y;
	}
	void pushdown(int x)
	{
		int l=ch[x][0],r=ch[x][1];
		if(l) v[l]+=t[x],t[l]+=t[x];
		if(r) v[r]+=t[x],t[r]+=t[x];
		t[x]=0;
	}
	void down(int x)
	{
		if(fa[x])
			down(fa[x]);
		pushdown(x);
	}
	void splay(int x,int y)
	{
		down(x);
		for(;fa[x]!=y;rotate(x))
			if(fa[fa[x]]!=y)
				rotate(lson(x)^lson(fa[x])?x:fa[x]);
		if(!y)
			rt=x;
	}
	int find(int val)
	{
		int x=rt,ans=0;
		while(x)
		{
			pushdown(x);
			if(v[x]<val)
				ans=x,x=ch[x][1];
			else
				x=ch[x][0];
		}
		return ans;
	}
	int pre(int x)
	{
		splay(x,0);
		for(x=ch[x][0];ch[x][1];x=ch[x][1]);
		return x;
	}
	int nxt(int x)
	{
		splay(x,0);
		for(x=ch[x][1];ch[x][0];x=ch[x][0]);
		return x;
	}
	void del(int x)
	{
		int y=pre(x),z=nxt(x);
		splay(y,0);
		splay(z,y);
		ch[z][0]=fa[x]=0;
	}
	void insert(int val)
	{
		int x=rt,y=0;
		while(x)
		{
			y=x;
			pushdown(x);
			x=ch[x][val>=v[x]];
		}
		sz++;
		x=sz;
		fa[x]=y;
		v[x]=val;
		if(y)
			ch[y][val>=v[y]]=x;
		splay(x,0);
	}
	void solve()
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int x=find(l),y=find(r);
		int z=nxt(y);
		if(x!=y)
		{
			splay(x,0);
			splay(z,x);
			v[ch[z][0]]++;
			t[ch[z][0]]++;
		}
		if(z!=2)
		{
			del(z);
			ans--;
		}
		insert(l);
		ans++;
	}
}
int main()
{
	sp::insert(-(1<<30));
	sp::insert(1<<30);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		sp::solve();
	printf("%d\n",ans);
	return 0;
}