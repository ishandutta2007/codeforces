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
int n;
const int xx=1e5+5;
struct node
{
	int to[26];
	int end;
}e[xx];
int cnt;
char c[xx];
int a(int &x)
{
	if(x)return x;
	return (x=++cnt);
}
void insert()
{
	int n=strlen(c);
	int last=0;
	for(int i=0;i<n;i++)last=a(e[last].to[c[i]-'a']);
	e[last].end=1;
}
int size[xx];
int son[xx];
int dep[xx];
void DFS(int x,int now)
{
	dep[x]=now;
	int maxx=-1;
	size[x]=1;
	for(int i=0;i<26;i++)
	{
		if(e[x].to[i])
		{
			DFS(e[x].to[i],now+1);
			size[x]+=size[e[x].to[i]];
			if(size[e[x].to[i]]>maxx)maxx=size[e[x].to[i]],son[x]=e[x].to[i];
		}
	}
}
multiset<int>v[xx];
multiset<int>s;
ll ans=0;
//void add(int x)
//{
////	cout<<x<<endl;
//	for(int i=0;i<26;i++)if(e[x].to[i])add(e[x].to[i]);
//	if(!x)return;
//	if(e[x].end)v.insert(dep[x]),ans+=dep[x];
//	else ans-=*(--v.end()),ans+=dep[x],v.erase(--v.end()),v.insert(dep[x]);
////	for(multiset<int>::iterator it=v.begin();it!=v.end();it++)cout<<*it<<" ";
////	puts("");
//}
void dfs(int x)
{
	for(int i=0;i<26;i++)
	{
		if(e[x].to[i]&&e[x].to[i]!=son[x])
		{
			dfs(e[x].to[i]);
			for(multiset<int>::iterator it=s.begin();it!=s.end();it++)v[x].insert(*it);
			s.clear();
		}
	}
	if(son[x])dfs(son[x]);
	for(multiset<int>::iterator it=v[x].begin();it!=v[x].end();it++)s.insert(*it);
	v[x].clear();
	if(x)
	{
		if(e[x].end)s.insert(dep[x]);
		else s.insert(dep[x]),s.erase(--s.end());
	}
	else 
	{
		ll ans=0;
		for(multiset<int>::iterator it=s.begin();it!=s.end();it++)ans+=(*it);
		cout<<ans<<"\n";
	}
//	cout<<x<<" qq "<<son[x]<<endl;
//	for(multiset<int>::iterator it=s.begin();it!=s.end();it++)cout<<*it<<" ";
//	puts("");
	
}
signed main(){
	int n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c);
		insert();
	}
	DFS(0,0);
	dfs(0);
	return 0;
}
/*
10
a
aa
aaaba
aaabb
aaba
abba
baa
babba
bbb
bbba
23
*/