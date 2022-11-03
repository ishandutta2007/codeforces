#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=998244353;
int n,a,b,all,pa[4444],ans,re[4444],cnt,cur,col[4444],p[4444];
char s[111111];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
}
bool f,flg[4444];
vector<int> g[4444],v;
void dfs(int i,int c)
{
	col[i]=c;v.push_back(i); 
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (col[to])
		{
			if (col[to]+col[i]!=3)
			{
				f=1;
				return;
			}
		}
		else
		{
			dfs(to,3-c);
		}
	}
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<n;i++)
	{
		a=n-i;b=n;all=a+b;
		for (int j=1;j<=2*all;j++) pa[j]=j;
		for (int j=1;j<=a;j++)
		{
			if (j!=a-j+1)
			{
				Union(j,a-j+1);
				Union(j+all,a-j+1+all);
			}
		}
		for (int j=1;j<=n;j++)
		{
			if (j!=n-j+1)
			{
				Union(a+j,a+n-j+1);
				Union(a+j+all,a+n-j+1+all);
			}
		}
		for (int j=1;j<=a;j++)
		{
			if (s[i+j-1]=='0') 
			{
				Union(j,a+i+j);
				Union(j+all,a+i+j+all);
			}
			else if (s[i+j-1]=='1')
			{
				Union(j,a+i+j+all);
				Union(j+all,a+i+j);
			}
		}
		f=0;
		for (int j=1;j<=all;j++)
		{
			if (root(j)==root(j+all)) 
			{
				f=1;
				break;
			}
		}
		if (f) continue;
		cnt=0;
		memset(re,0,sizeof(re));
		for (int j=1;j<=2*all;j++)
		{
			int rt=root(j);
			if (!re[rt]) re[rt]=++cnt;
		}
		memset(flg,0,sizeof(flg));
		for (int j=0;j<i;j++)
		{
			if (s[j]=='0')
			{
				int rt=root(a+j+1+all);
				flg[re[rt]]=1;
			}
			else if (s[j]=='1')
			{
				int rt=root(a+j+1);
				flg[re[rt]]=1;
			}
		}
		int rt=root(1);
		flg[re[rt]]=1;
		for (int j=1;j<=cnt;j++) g[j].clear();
		for (int j=1;j<=all;j++)
		{
			int rt1=root(j),rt2=root(j+all);
			g[re[rt1]].push_back(re[rt2]);
			g[re[rt2]].push_back(re[rt1]);  
		}
		memset(col,0,sizeof(col));
		cur=1;f=0;
		for (int j=1;j<=cnt;j++)
		{
			if (!col[j])
			{
				v.clear();
				dfs(j,1);
				if (f) break;
				bool rev=0,gg=0;
				for (int h=0;h<v.size();h++)
				{
					if (flg[v[h]]) gg=1;
					if (flg[v[h]] && col[v[h]]!=1) 
					{
						rev=1;
						break;
					}
				}
				if (rev)
				{
					for (int h=0;h<v.size();h++)
					{
						if (flg[v[h]] && col[v[h]]!=2) 
						{
							f=1;
							break;
						}
					}
				}
				if (f) break;
				if (!gg) cur=cur*2%mod;
			}
		}
	//	if (!f) cout<<i<<" "<<cur<<endl;
		if (!f) ans=(ans+cur)%mod;
	}
	printf("%d\n",ans);
	return Accepted;
}