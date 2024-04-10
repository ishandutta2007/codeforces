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
const int xx=2e6+5;
char s[xx];
struct nod
{
	int to[27];
	int size,link;
}e[xx];
int last,cst;
void add(int x)
{
	int now=++cst,p=last;e[now].size=e[last].size+1,last=now;
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
}
struct segment
{
	int sum,l,r;
}tree[xx<<2];
int cnt;
int root[xx];
void insert(int &k,int l,int r,int x)
{
	int s=k;
	k=++cnt;
	tree[k]=tree[s];
	tree[k].sum=max(tree[k].sum,x);
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)insert(tree[k].l,l,mid,x);
	else insert(tree[k].r,mid+1,r,x);
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	int now=++cnt;
	tree[now].sum=max(tree[x].sum,tree[y].sum);
	tree[now].l=merge(tree[x].l,tree[y].l);
	tree[now].r=merge(tree[x].r,tree[y].r);
	return now;
}
int rd[xx];
void tp()
{
	for(int i=2;i<=cst;i++)rd[e[i].link]++;
	queue<int>q;
	for(int i=2;i<=cst;i++)if(!rd[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		rd[e[x].link]--;
		if(!rd[e[x].link])q.push(e[x].link);
		root[e[x].link]=merge(root[e[x].link],root[x]);
	}
}
int ask(int k,int l,int r,int x,int y)
{
	if(!k)return 0;
	if(r<x||y<l)return 0;
	if(x<=l&&r<=y)return tree[k].sum;
	int mid=l+r>>1;
	return max(ask(tree[k].l,l,mid,x,y),ask(tree[k].r,mid+1,r,x,y));
}
signed main(){
//	freopen("a.out","w",stdout);
	last=cst=1;
	scanf("%s",s);
	int pp=strlen(s);
	for(int i=0;i<pp;i++)add(s[i]-'a');
	last=1;
	for(int i=0;i<pp;i++)last=e[last].to[s[i]-'a'],insert(root[last],1,pp,i+1);
	tp();
	int q=read();
	while(q--)
	{
		int l,r;
		l=read();
		r=read();
		scanf("%s",s);
		int p=strlen(s);
		int last=1,ans=-1,rlast=-1;
		s[p]='a'-1;
		for(int i=0;i<=p;i++)
		{
			for(int j=s[i]-'a'+1;j<26;j++)
			{
				if(!e[last].to[j])continue;
				int o=ask(root[e[last].to[j]],1,pp,l,r);
				if(o-i>=l)
				{
					ans=i,rlast=last;break;
				}
			}
			if(i==p)break;
			last=e[last].to[s[i]-'a'];
			int s=ask(root[last],1,pp,l,r);
			if(!last||!s||s-i<l)break;
		}
		if(ans==-1)puts("-1");
		else 
		{
			for(int i=0;i<ans;i++)cout<<s[i];
			last=rlast;
			for(int j=s[ans]-'a'+1;j<26;j++)
			{
				if(!e[last].to[j])continue;
				int o=ask(root[e[last].to[j]],1,pp,l,r);
				if(o-ans>=l)
				{
					cout<<char(j+'a');break;
				}
			}
			puts("");
		}
	}
	return 0;
}