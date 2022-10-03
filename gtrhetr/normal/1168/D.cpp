#include<bits/stdc++.h>
using namespace std;

struct node { int t,next; }a[150010];

vector<int> v[150010];

int sum[150010][26],num[150010][26],s[150010][26],s1[150010];
int ch[150010][2],head[150010],fa[150010],dep[150010],mx[150010],son[150010],from[150010],di[150010],n,m,cnt,tot;
char S[150010],str[110];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void printyes() { putchar('S');putchar('h');putchar('i');putchar(' '); }
inline void printno() { putchar('F');putchar('o');putchar('u');putchar(' '); }

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void pre_dfs(int x)
{
	v[dep[x]].push_back(x);
	mx[x]=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		dep[t]=dep[x]+1;
		if (!ch[x][0]) ch[x][0]=t;
		else ch[x][1]=t;
		pre_dfs(t);
		mx[x]=max(mx[x],mx[t]+1);
	}
}

inline int find(const int &x) { return (x==from[x])?x:from[x]=find(from[x]); }

inline void check()
{
	if (cnt) { printno();putchar('\n');return; }
	printyes();
	int now=0;
	for (int i=0;i<26;i++) now+=sum[1][i];
	int res=0;
	for (int j=0;j<26;j++) res+=(j+1)*(mx[1]-now+sum[1][j]);
	print(res);
}

int main()
{
	n=rd();m=rd();
	for (int i=2;i<=n;i++) fa[i]=rd(),scanf("%s",S+i),add(fa[i],i);
	for (int i=2;i<=n;i++) son[fa[i]]++;
	dep[1]=1;pre_dfs(1);
	int id=0;
	for (int i=1;i<=n;i++) if (!son[i]) id=i;
	bool flag=true;
	for (int i=1;i<=n;i++) if (!son[i]&&dep[i]!=dep[id]) { flag=false;break; }
	if (!flag)
	{
		for (int i=1;i<=m;i++) printno(),putchar('\n');
		return 0;
	}
	for (int i=1;i<=n;i++) from[i]=i,di[i]=i;
	for (int i=dep[id]-1;i;i--)
	{
		bool flag=true;
		for (int t:v[i]) if (son[t]>1) flag=false;
		if (!flag) continue;
		for (int x:v[i])
		{
			int t=a[head[x]].t;
			from[t]=x;di[x]=di[t];
			ch[x][0]=ch[t][0];ch[x][1]=ch[t][1];
		}
	}
	cnt=0;
	for (int i=1;i<=n;i++) if (S[i]!='?') num[find(i)][S[i]-'a']++;
	for (int i=n;i;i--) if (find(i)==i)
	{
		for (int j=0;j<26;j++) s[i][j]=max(sum[ch[i][0]][j],sum[ch[i][1]][j]);
		for (int j=0;j<26;j++) s1[i]+=s[i][j];
		if (s1[i]>mx[di[i]]) cnt++;
		for (int j=0;j<26;j++) sum[i][j]=s[i][j]+num[i][j];
	}
	for (int i=1;i<=n;i++) fa[i]=find(fa[i]);
	while (m--)
	{
		int x=rd();scanf("%s",str+1);
		if (str[1]==S[x]) { check();continue; }
		int h1=-1,h2=-1;
		if (str[1]=='?') num[find(x)][S[x]-'a']--,h1=S[x]-'a';
		else if (S[x]=='?') num[find(x)][str[1]-'a']++,h1=str[1]-'a';
		else num[find(x)][S[x]-'a']--,num[find(x)][str[1]-'a']++,h1=S[x]-'a',h2=str[1]-'a';
		S[x]=str[1];
		for (int i=find(x);i;i=fa[i])
		{
			if (s1[i]>mx[di[i]]) cnt--;
			if (h1!=-1)
			{
				s1[i]-=s[i][h1];
				s[i][h1]=max(sum[ch[i][0]][h1],sum[ch[i][1]][h1]);
				s1[i]+=s[i][h1];
				sum[i][h1]=s[i][h1]+num[i][h1];
			}
			if (h2!=-1)
			{
				s1[i]-=s[i][h2];
				s[i][h2]=max(sum[ch[i][0]][h2],sum[ch[i][1]][h2]);
				s1[i]+=s[i][h2];
				sum[i][h2]=s[i][h2]+num[i][h2];
			}
			if (s1[i]>mx[di[i]]) cnt++;
		}
		check();
	}
	return 0;
}