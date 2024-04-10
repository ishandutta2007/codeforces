#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
char s[xx];
char c[xx];
int n;
namespace SG
{
	struct node
	{
		ll maxx;
		int id,l,r;
		node(){}
		node(int a,int b,int c,int d){maxx=a,id=b,l=c,r=d;}
	}e[xx<<4];
	node empt(-1,1e5,0,0);
	int cst;
	int root[xx];
	void update(node &k,node x,node y)
	{
		if(x.maxx>=y.maxx)k.maxx=x.maxx,k.id=x.id;
		else k.maxx=y.maxx,k.id=y.id;
	}
	void insert(int &k,int l,int r,int x)
	{
		int o=k;
		k=++cst;
		e[k]=e[o];
		if(l==r)
		{
			e[k].maxx++,e[k].id=x;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid)insert(e[k].l,l,mid,x);
		else insert(e[k].r,mid+1,r,x);
		update(e[k],e[e[k].l],e[e[k].r]);
	}
	int merge(int x,int y,int l,int r)
	{
		if(!x||!y)return x+y;
		int now=++cst;
		if(l==r)e[now].maxx=e[x].maxx+e[y].maxx,e[now].id=l;
		if(l==r)return now;
		int mid=l+r>>1;
		e[now].l=merge(e[x].l,e[y].l,l,mid);
		e[now].r=merge(e[x].r,e[y].r,mid+1,r);
		update(e[now],e[e[now].l],e[e[now].r]);
		return now;
	}
	node ask(int k,int l,int r,int x,int y)
	{
		if(!k)return node(0,x,0,0);
		if(r<x||y<l)return empt;
		if(x<=l&&r<=y)return e[k];
		int mid=l+r>>1;
		if(y<=mid)return ask(e[k].l,l,mid,x,y);
		else if(x>=mid+1)return ask(e[k].r,mid+1,r,x,y);
		node a=ask(e[k].l,l,mid,x,mid);
		node b=ask(e[k].r,mid+1,r,mid+1,y);
		node c;
		update(c,a,b);
		return c;
	}
}
namespace SAM
{
	struct node
	{
		int to[26];
		int size;
		int link;
	}e[xx];
	int last,cst;
	void add(int x,int id)
	{
		if(e[last].to[x])
		{
			int p=last,q=e[last].to[x];
			if(e[p].size+1==e[q].size)last=q;
			else 
			{
				int s=++cst;
				e[s].size=e[p].size+1;
				for(int i=0;i<26;i++)e[s].to[i]=e[q].to[i];
				e[s].link=e[q].link;
				e[q].link=s;
				while(p&&e[p].to[x]==q)e[p].to[x]=s,p=e[p].link;
				last=s;
			}
			SG::insert(SG::root[last],1,n,id);
			return;
		}
		int now=++cst,p=last;e[now].size=e[last].size+1;last=now;
		while(p&&!e[p].to[x])e[p].to[x]=now,p=e[p].link;
		if(!p)e[now].link=1;
		else 
		{
			int q=e[p].to[x];
			if(e[p].size+1==e[q].size)e[now].link=q;
			else 
			{
				int s=++cst;
				e[s].size=e[p].size+1;
				for(int i=0;i<26;i++)e[s].to[i]=e[q].to[i];
				e[s].link=e[q].link;
				e[q].link=e[now].link=s;
				while(p&&e[p].to[x]==q)e[p].to[x]=s,p=e[p].link;
			}
		}
		SG::insert(SG::root[last],1,n,id);
	}
	int f[xx][21];
	int len[xx],to[xx];
	int id[xx];
	int T[xx];
	void tp()
	{
		for(int i=1;i<=cst;i++)T[e[i].size]++;
		for(int i=1;i<=cst;i++)T[i]+=T[i-1];
		for(int i=1;i<=cst;i++)id[T[e[i].size]--]=i;
		for(int i=cst;i>=1;i--)
		{
			int x=id[i];
			SG::root[e[x].link]=SG::merge(SG::root[e[x].link],SG::root[x],1,n);
		}
	}
	void solve()
	{
		cst=1;
		scanf("%s",c);
		n=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			int p=strlen(s);
			last=1;
			for(int j=0;j<p;j++)add(s[j]-'a',i);
		}
		for(int i=1;i<=cst;i++)f[i][0]=e[i].link;
		for(int j=1;j<=20;j++)
		{
			for(int i=1;i<=cst;i++)
			{
				f[i][j]=f[f[i][j-1]][j-1];
			}
		}
		tp();
		int p=strlen(c);
		last=1;int l=0;
		for(int i=0;i<p;i++)
		{
			while(last!=1&&!e[last].to[c[i]-'a'])last=e[last].link,l=e[last].size;
			if(e[last].to[c[i]-'a'])last=e[last].to[c[i]-'a'],l++;
			len[i+1]=l;to[i+1]=last;
		}
		int q=read();//merge
		while(q--)
		{
			int a,b,l,r;
			a=read();
			b=read();
			l=read();
			r=read();
			if(len[r]<(r-l+1))
			{
				cout<<a<<" "<<0<<"\n";
				continue;
			}
			int now=to[r];
			for(int i=20;i>=0;i--)
			{
				if(f[now][i]&&e[f[now][i]].size>=r-l+1)now=f[now][i];
			}
			SG::node t=SG::ask(SG::root[now],1,n,a,b);
			cout<<t.id<<" "<<t.maxx<<"\n";
		}
	}
}
signed main(){
	SAM::solve();
    return 0;
}