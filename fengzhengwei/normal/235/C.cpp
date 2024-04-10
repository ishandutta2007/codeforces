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
struct node
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
int vis[xx];
int size[xx];
int rd[xx];
void tp()
{
	int ss=strlen(s);
	last=1;
	for(int i=0;i<ss;i++)last=e[last].to[s[i]-'a'],size[last]++;
	for(int i=2;i<=cst;i++)rd[e[i].link]++;
	queue<int>q;
	for(int i=2;i<=cst;i++)if(!rd[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();
//		cout<<x<<" "<<size[x]<<endl;
		q.pop();
		size[e[x].link]+=size[x];
		rd[e[x].link]--;
		if(rd[e[x].link]==0)q.push(e[x].link);
	}
}
signed main(){
	last=cst=1;
	scanf("%s",s);
	int p=strlen(s);
	for(int i=0;i<p;i++)add(s[i]-'a');
	tp();
	int q=read();
	for(int i=1;i<=q;i++)
	{
		scanf("%s",s);
		int l=0;
		p=strlen(s);
		int last=1;
		for(int j=0;j<p;j++)
		{
			while(last!=1&&!e[last].to[s[j]-'a'])last=e[last].link,l=min(e[last].size,l);
			if(e[last].to[s[j]-'a'])last=e[last].to[s[j]-'a'],l++;
		}
		ll ans=0;
		stack<int>stk;
		if(l==p)ans+=size[last],vis[last]=i,stk.push(last);
		for(int j=0;j<p;j++)
		{
			if(l==p)
			{
				l--;
				if(l==e[e[last].link].size)last=e[last].link;
			}
			while(last!=1&&!e[last].to[s[j]-'a'])last=e[last].link,l=min(e[last].size,l);
			if(e[last].to[s[j]-'a'])last=e[last].to[s[j]-'a'],l++;
			if(l==p)
			{
				if(vis[last]!=i)ans+=size[last],vis[last]=i,stk.push(last);
			}
		}
		while(!stk.empty())vis[stk.top()]=0,stk.pop();
		cout<<ans<<"\n";
	}
	return 0;
}