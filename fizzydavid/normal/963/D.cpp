//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
int n,q;
char s[100111];
int go[200111][26],tot=1;
int pre[200111],len[200111];
int preid[200111];
int append(int p,int c)
{
	int np=++tot;
	len[np]=len[p]+1;
	while(p&&!go[p][c])go[p][c]=np,p=pre[p];
	if(p==0)
	{
		pre[np]=1;
		return np;
	}
	int q=go[p][c];
	if(len[q]==len[p]+1)
	{
		pre[np]=q;
		return np;
	}
	else
	{
		int nq=++tot;
		len[nq]=len[p]+1;
		pre[nq]=pre[q];
		pre[np]=pre[q]=nq;
		copy(go[q],go[q]+26,go[nq]);
		while(p&&go[p][c]==q)go[p][c]=nq,p=pre[p];
	}
	return np;
}
vector<int> son[200111];
void init()
{
	for(int i=2;i<=tot;i++)
	{
		son[pre[i]].PB(i);
	}
}
int v[100111],vn;
void dfs(int x)
{
	if(preid[x])v[vn++]=preid[x];
	for(auto u:son[x])
	{
		dfs(u);
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int st=1;
	for(int i=1;i<=n;i++)
	{
		st=append(st,s[i]-'a');
		preid[st]=i;
	}
	init();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int k;
		scanf("%d%s",&k,s+1);
		int l=strlen(s+1);
		int p=1;
		for(int j=1;j<=l;j++)
		{
			p=go[p][s[j]-'a'];
		}
		if(p==0)puts("-1");
		else
		{
			vn=0;
			dfs(p);
			sort(v,v+vn);
			if(vn<k)puts("-1");
			else
			{
				int ans=mod;
				for(int j=k-1;j<vn;j++)
				{
					ans=min(ans,v[j]-v[j-k+1]);
				}
				printf("%d\n",ans+l);
			}
		}
	}
	return 0;
}