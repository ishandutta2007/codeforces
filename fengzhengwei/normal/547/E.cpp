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
int n,m;
string a[2000005];
char c[2000005];
struct node
{
	int t,id,op,x;
	bool operator<(const node&w)const
	{
		return t<w.t;
	}
}s[2000005];
struct trie
{
	int to[26];
	int fail;
}tree[600005];
struct edge
{
	int next,to;
}e[2000005];
int cnt;
int h[2000005];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int cst;
int to[2000005];
void insert(int id)
{
	int last=0;
	int p=strlen(c);
	for(int i=0;i<p;i++)
	{
		if(!tree[last].to[c[i]-'a'])tree[last].to[c[i]-'a']=++cst;
		last=tree[last].to[c[i]-'a'];
	}
	to[id]=last;
//	cout<<id<<" "<<last<<endl;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(tree[0].to[i])q.push(tree[0].to[i]);
	}
	while(!q.empty())
	{
		int x=q.front();
		add(tree[x].fail,x);
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(!tree[x].to[i])tree[x].to[i]=tree[tree[x].fail].to[i];
			else tree[tree[x].to[i]].fail=tree[tree[x].fail].to[i],q.push(tree[x].to[i]);
		}
	}
}
int ids[2000005];
int size[2000005];
int sss;
void dfs(int x)
{
	ids[x]=++sss;
//	cout<<sss<<endl;
//	cout<<x<<"qqqq"<<endl;
	size[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		dfs(e[i].to);
		size[x]+=size[e[i].to];
	}
}
int lb(int x)
{
	return x&(-x);
}
ll sum[2000005];
void ad(int x,int y)
{
	for(;x<=sss;x+=lb(x))sum[x]+=y;
}
ll ask(int x)
{
	if(x==0)return 0;
	ll ans=0;
	for(;x;x-=lb(x))ans+=sum[x];
//	cout<<"qweqe"<<o<<" "<<ans<<" "<<cst<<endl;
	return ans;
}
ll ans[2000005];
void run(string s)
{
	int o=s.size();
	int last=0;
	for(int i=0;i<o;i++)
	{
//		cout<<last<<"W"<<endl;
		last=tree[last].to[s[i]-'a'];
		ad(ids[last],1);
	}
}
signed main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c);
		a[i]=c;
		insert(i);
	}
	getfail();
	dfs(0);
	int tot=0;
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		l=read();
		r=read();
		k=read();
		s[++tot].id=i;
		s[tot].op=-1;
		s[tot].x=to[k];
		s[tot].t=l-1;
		s[++tot].id=i;
		s[tot].op=1;
		s[tot].x=to[k];
		s[tot].t=r;
	}
	sort(s+1,s+tot+1);
	int now=0;
	while(s[now+1].t==0)now++;
//	cout<<now<<endl;
	for(int i=1;i<=n;i++)
	{
		run(a[i]);
		while(s[now+1].t==i)
		{
			now++;
//			cout<<s[now].id<<" "<<s[now].t<<" "<<s[now].x<<" "<<s[now].op<<" "<<size[s[now].x]<<" "<<(ask(ids[s[now].x]+size[s[now].x]-1)-ask(ids[s[now].x]-1))<<endl;
//			cout<<now<<endl;
			ans[s[now].id]+=(ask(ids[s[now].x]+size[s[now].x]-1)-ask(ids[s[now].x]-1))*s[now].op;
		}
	}
//	cout<<now<<endl;
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}