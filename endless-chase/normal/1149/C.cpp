#include<bits/stdc++.h>
using namespace std;
int n,q,sz,x,y;
char s[222222];
struct segtree
{
	int l,r,a,b,a1,a2,b1,b2,dis;//max(a+b),max(b-a),max(a-b),max(a+b);
}tree[888888];
void pushup(int node)
{
	tree[node].a=tree[node<<1].a+max(0,tree[(node<<1)|1].a-tree[node<<1].b);
	tree[node].b=tree[(node<<1)|1].b+max(0,tree[node<<1].b-tree[(node<<1)|1].a);
	tree[node].dis=max(tree[node<<1].b1+tree[(node<<1)|1].a1,tree[node<<1].b2+tree[(node<<1)|1].a2);
	tree[node].dis=max(tree[node].dis,max(tree[node<<1].dis,tree[(node<<1)|1].dis));
	tree[node].a1=max(tree[node<<1].a1,max(tree[node<<1].a+tree[node<<1].b+tree[(node<<1)|1].a2,tree[node<<1].a-tree[node<<1].b+tree[(node<<1)|1].a1));
	tree[node].a2=max(tree[node<<1].a2,tree[node<<1].b-tree[node<<1].a+tree[(node<<1)|1].a2);
	tree[node].b1=max(tree[(node<<1)|1].b1,tree[(node<<1)|1].a-tree[(node<<1)|1].b+tree[node<<1].b1);
	tree[node].b2=max(tree[(node<<1)|1].b2,max(tree[(node<<1)|1].a+tree[(node<<1)|1].b+tree[node<<1].b1,tree[(node<<1)|1].b-tree[(node<<1)|1].a+tree[node<<1].b2));
}
void build(int l,int r,int node)
{
	tree[node].l=l;tree[node].r=r;
	if (l==r)
	{
		if (s[l-1]=='(') 
		{
			tree[node].b=1;
			tree[node].a1=1;tree[node].a2=1;tree[node].b1=0;tree[node].b2=1;
			tree[node].dis=1;
		}
		else 
		{
			tree[node].a=1;	
			tree[node].a1=1;tree[node].a2=0;tree[node].b1=1;tree[node].b2=1;
			tree[node].dis=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
void update(int x,int l,int r,int node,int f)
{
	if (l==r)
	{
		if (!f)
		{
			tree[node].b=1;tree[node].a=0;
			tree[node].a1=1;tree[node].a2=1;tree[node].b1=0;tree[node].b2=1;
			tree[node].dis=1;
		}
		else
		{
			tree[node].a=1;tree[node].b=0;
			tree[node].a1=1;tree[node].a2=0;tree[node].b1=1;tree[node].b2=1;
			tree[node].dis=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	if (x>mid) update(x,mid+1,r,(node<<1)|1,f);
	else update(x,l,mid,node<<1,f);
	pushup(node);
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s);
	sz=strlen(s);
	build(1,sz,1);
	printf("%d\n",tree[1].dis);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		if (s[x]=='(') update(y+1,1,sz,1,0);
		else update(y+1,1,sz,1,1);
		if (s[y]=='(') update(x+1,1,sz,1,0);
		else update(x+1,1,sz,1,1);
		swap(s[x],s[y]);
		printf("%d\n",tree[1].dis);
	}
	return 0;
}