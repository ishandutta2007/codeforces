#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define inf 2123333333

unordered_map<ull,bool> mp[5010];

int f[5010],w[10010],c[10010],n,a,b;
char s[5010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

struct tree
{
	int ch[10010][26],fa[10010],len[10010],id[10010],tot,last;
	bool bo[10010][5010];
	inline void init() { tot=last=1; }
	inline void insert(int x,int y)
	{
		int p=last,np=++tot;
		len[np]=len[p]+1;id[np]=y;
		for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
		if (!p) fa[np]=1;
		else
		{
			int q=ch[p][x];
			if (len[q]==len[p]+1) fa[np]=q;
			else
			{
				int nq=++tot;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				len[nq]=len[p]+1;
				fa[nq]=fa[q];fa[q]=fa[np]=nq;
				for (;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
			}
		}
		last=np;
	}
	inline void build()
	{
		for (int i=1;i<=tot;i++) w[len[i]]++;
		for (int i=1;i<=tot;i++) w[i]+=w[i-1];
		for (int i=tot;i;i--) c[w[len[i]]--]=i;
		for (int i=tot;i;i--)
		{
			int x=c[i];
			if (id[x]) bo[x][id[x]]=true;
			if (fa[x]) for (int j=1;j<=n;j++) bo[fa[x]][j]|=bo[x][j];
		}
		for (int i=1;i<=tot;i++) for (int j=1;j<=n;j++) bo[i][j]|=bo[i][j-1];
	}
}sam;

int main()
{
	n=rd();a=rd();b=rd();
	scanf("%s",s+1);
	f[0]=0;
	for (int i=1;i<=n;i++) f[i]=inf;
	sam.init();
	for (int i=1;i<=n;i++) sam.insert(s[i]-'a',i);
	sam.build();
	int now=1;
	for (int i=1;i<=n;i++)
	{
		f[i]=min(f[i],f[i-1]+a);
		now=sam.ch[now][s[i]-'a'];
		int hh=now;
		for (int j=1;j<=i;j++)
		{
			while (sam.len[sam.fa[hh]]>=i-j+1) hh=sam.fa[hh];
			if (sam.bo[hh][j-1]) f[i]=min(f[i],f[j-1]+b);
		}
	}
	printf("%d\n",f[n]);
	return 0;
}