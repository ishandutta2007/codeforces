#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int num[1010][1010],d[1010][1010],n,m,Q;
bool inq[1010][1010];
char s[1010];

inline ll rd()
{
	ll x=0;char ch=getchar();
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

queue<pii> q;

inline void bfs()
{
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (inq[i][j]) d[i][j]=0,q.push(pii(i,j));
	while (!q.empty())
	{
		pii hh=q.front();q.pop();
		int x=hh.first,y=hh.second;
		for (int i=0;i<4;i++)
		{
			int t1=x+dx[i],t2=y+dy[i];
			if (t1<1||t1>n||t2<1||t2>m) continue;
			if (inq[t1][t2]) continue;
			inq[t1][t2]=true;d[t1][t2]=d[x][y]+1;
			q.push(pii(t1,t2));
		}
	}
}

int main()
{
	n=rd();m=rd();Q=rd();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) num[i][j]=s[j]-'0';
	}
	bool flag=false;
	for (int i=1;i<=n;i++) for (int j=1;j<m;j++) if (num[i][j]==num[i][j+1]) flag=true;
	for (int i=1;i<n;i++) for (int j=1;j<=m;j++) if (num[i][j]==num[i+1][j]) flag=true;
	if (!flag)
	{
		while (Q--)
		{
			int x=rd(),y=rd();rd();
			print(num[x][y]);
		}
		return 0;
	}
	for (int i=1;i<=n;i++) for (int j=1;j<m;j++) if (num[i][j]==num[i][j+1]) inq[i][j]=inq[i][j+1]=true;
	for (int i=1;i<n;i++) for (int j=1;j<=m;j++) if (num[i][j]==num[i+1][j]) inq[i][j]=inq[i+1][j]=true;
	bfs();
	while (Q--)
	{
		int x=rd(),y=rd();ll t=rd();
		if (d[x][y]>t) print(num[x][y]);
		else print(num[x][y]^((t-d[x][y])&1));
	}
	return 0;
}