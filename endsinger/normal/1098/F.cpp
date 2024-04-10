#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,q,ch[N][26],f[N],len[N],sz=1,las=1,p[N],ts[N],mx[N],tp[N],dfn[N],c,b0[N];
long long b1[N],ans[N];
char s[N];
vector<int>e[N];
struct nd{int x,y,z;};
vector<nd>a[N],q1[N],q2[N];
int ins(int x)
{
	int p=las,c=++sz;
	len[c]=len[p]+1;
	while(p&&!ch[p][x])
	{
		ch[p][x]=c;
		p=f[p];
	}
	if(!p)
		f[c]=1;
	else
	{
		int q=ch[p][x];
		if(len[p]+1==len[q])
			f[c]=q;
		else
		{
			int nq=++sz;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			f[nq]=f[q],len[nq]=len[p]+1;
			while(p&&ch[p][x]==q)
			{
				ch[p][x]=nq;
				p=f[p];
			}
			f[q]=f[c]=nq;
		}
	}
	las=c;
	return c;
}
void dfs1(int u)
{
	ts[u]=1;
	for(auto v:e[u])
	{
		dfs1(v);
		if(ts[v]>ts[mx[u]])
			mx[u]=v;
		ts[u]+=ts[v];
	}
}
void dfs2(int u,int t)
{
	tp[u]=t,c++,dfn[u]=c;
	if(mx[u])
		dfs2(mx[u],t);
	for(auto v:e[u])
		if(v!=mx[u])
			dfs2(v,v);
}
void add(int x)
{
	for(int i=x;i<=sz;i+=i&(-i))
	{
		b0[i]++;
		b1[i]+=x;
	}
}
void cls(int x)
{
	for(int i=x;i<=sz;i+=i&(-i))
		b0[i]=b1[i]=0;
}
int ask0(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b0[i];
	return v;
}
long long ask1(int x)
{
	long long v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b1[i];
	return v;
}
void add1(int i)
{
	int x=p[i];
	while(x>1)
	{
		int y=tp[x];
		a[y].push_back({i,len[x]-len[f[y]],i+len[f[y]]});
		x=f[y];
	}
}
void add2(int l,int r,int d)
{
	int x=p[l];
	while(x>1)
	{
		int y=tp[x];
		if(len[f[y]]<r-l+1)
		{
			q1[y].push_back({l-1,min(len[x],r-l+1)-len[f[y]],d});
			q2[y].push_back({r+1,min(len[x],r-l+1)-len[f[y]],d});
		}
		x=f[y];
	}
}
bool cmp1(nd a,nd b){return a.x<b.x;}
bool cmp2(nd a,nd b){return a.y+a.z<b.y+b.z;}
void sol(vector<nd>a,vector<nd>q1,vector<nd>q2)
{
	if(q1.size())
	{
		sort(a.begin(),a.end(),cmp1);
		sort(q1.begin(),q1.end(),cmp1);
		int i=0;
		for(auto q:q1)
		{
			while(i<a.size()&&a[i].x<=q.x)
			{
				add(a[i].y);
				i++;
			}
			ans[q.z]-=1ll*q.y*(i-ask0(q.y))+ask1(q.y);
		}
		for(auto q:a)
			cls(q.y);
	}
	if(q2.size())
	{
		sort(a.begin(),a.end(),cmp2);
		sort(q2.begin(),q2.end(),cmp1);
		int i=0;
		for(auto q:q2)
		{
			while(i<a.size()&&a[i].y+a[i].z<=q.x)
			{
				add(a[i].y);
				i++;
			}
			ans[q.z]+=1ll*q.y*(i-ask0(q.y))+ask1(q.y);
		}
		for(auto q:a)
			cls(q.y);
		reverse(a.begin(),a.end());
		reverse(q2.begin(),q2.end());
		i=0;
		for(auto q:q2)
		{
			while(i<a.size()&&a[i].y+a[i].z>q.x)
			{
				add(a[i].z);
				i++;
			}
			ans[q.z]+=1ll*q.x*ask0(q.x)-ask1(q.x);
			if(q.x>q.y)
				ans[q.z]-=1ll*(q.x-q.y)*ask0(q.x-q.y)-ask1(q.x-q.y);
		}
		for(auto q:a)
			cls(q.z);
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=n;i>=1;i--)
		p[i]=ins(s[i]-'a');
	for(int i=2;i<=sz;i++)
		e[f[i]].push_back(i);
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		add1(i);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		add2(l,r,i);
	}
	for(int i=1;i<=sz;i++)
		sol(a[i],q1[i],q2[i]);
	for(int i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}