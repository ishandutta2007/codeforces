#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,q,nxt[111111][26],p[4],x,s1,s2,s3,dp[44444444];
pair<int,pair<int,int> > que[1111];
char s[111111],opt[11],cc[11];
int get(int x,int y,int z)
{
	return (x*s2*s3+y*s3+z);
}
struct trie
{
	int son[1111][26],sz,fa[1111];
	trie()
	{
		memset(son,0,sizeof(son));
		memset(fa,0,sizeof(fa));
		sz=0;
	}
}t[4];
vector<pair<int,int> > g1[1111],g2[1111],g3[1111];
void bfs()
{
	queue<int> q;
	int all=get(s1-1,s2-1,s3-1),x,y,z;
	for (int i=0;i<=all;i++) dp[i]=1e9;
	dp[0]=0;
	q.push(0);
	while(!q.empty())
	{
		int cur=q.front();q.pop();
		x=cur/(s2*s3);y=(cur/s3)%s2;z=cur%s3;
		for (int i=0;i<g1[x].size();i++)
		{
			int to=g1[x][i].first,val=g1[x][i].second,tp=get(to,y,z);
			if (dp[tp]>1e8)
			{
				q.push(tp);
				dp[tp]=nxt[dp[cur]][val]; 
			}
			else if (dp[tp]>nxt[dp[cur]][val]) dp[tp]=nxt[dp[cur]][val];
		}
		for (int i=0;i<g2[y].size();i++)
		{
			int to=g2[y][i].first,val=g2[y][i].second,tp=get(x,to,z);
			if (dp[tp]>1e8)
			{
				q.push(tp);
				dp[tp]=nxt[dp[cur]][val]; 
			}
			else if (dp[tp]>nxt[dp[cur]][val]) dp[tp]=nxt[dp[cur]][val];
		}
		for (int i=0;i<g3[z].size();i++)
		{
			int to=g3[z][i].first,val=g3[z][i].second,tp=get(x,y,to);
			if (dp[tp]>1e8)
			{
				q.push(tp);
				dp[tp]=nxt[dp[cur]][val]; 
			}
			else if (dp[tp]>nxt[dp[cur]][val]) dp[tp]=nxt[dp[cur]][val];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s);
	for (int i=0;i<26;i++) nxt[n][i]=nxt[n+1][i]=n+1;
	for (int i=n-2;i>=0;i--)
	{
		for (int j=0;j<26;j++) nxt[i+1][j]=nxt[i+2][j];
		nxt[i+1][s[i+1]-'a']=i+2;
	}
	for (int i=0;i<26;i++) nxt[0][i]=nxt[1][i];
	nxt[0][s[0]-'a']=1;
	p[1]=p[2]=p[3]=0;
	for (int i=1;i<=q;i++)
	{
		scanf("%s%d",opt,&x);
		if (opt[0]=='+')
		{
			scanf("%s",cc);
			if (!t[x].son[p[x]][cc[0]-'a']) 
			{
				t[x].son[p[x]][cc[0]-'a']=++t[x].sz;
				t[x].fa[t[x].sz]=p[x];
				p[x]=t[x].sz;
			}
			else
			{
				p[x]=t[x].son[p[x]][cc[0]-'a'];
			}
		}
		else
		{
			p[x]=t[x].fa[p[x]];
		}
		que[i]=make_pair(p[1],make_pair(p[2],p[3]));
	}
	s1=t[1].sz;s2=t[2].sz;s3=t[3].sz;s1++;s2++;s3++;
	for (int i=0;i<s1;i++)
	{
		for (int j=0;j<26;j++)
		{
			if (t[1].son[i][j]) g1[i].push_back(make_pair(t[1].son[i][j],j)); 
		}
	}
	for (int i=0;i<s2;i++)
	{
		for (int j=0;j<26;j++)
		{
			if (t[2].son[i][j]) g2[i].push_back(make_pair(t[2].son[i][j],j)); 
		}
	}
	for (int i=0;i<s3;i++)
	{
		for (int j=0;j<26;j++)
		{
			if (t[3].son[i][j]) g3[i].push_back(make_pair(t[3].son[i][j],j)); 
		}
	}
	bfs();
	for (int i=1;i<=q;i++)
	{
		if (dp[get(que[i].first,que[i].second.first,que[i].second.second)]<=n) printf("yEs\n");
		else printf("nO\n");
	}
	return Accepted;
}