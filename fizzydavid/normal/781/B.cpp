//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,x[1011],y[1011],ans[1011];
bool vis[30011];
char s[22],t[22];
vector<pair<int,int> >con[30011];
void setans(int i,int v)
{
	if(ans[i]==-1)
	{
		ans[i]=v;
	}
	else if(ans[i]!=v)ans[i]=-233;
}
bool mk[30011];
bool dfs(int x,int pre=-1)
{
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		if(mk[con[x][i].FF])return true;
		ans[con[x][i].SS]=con[x][i].FF;
		mk[con[x][i].FF]=1;
		if(!vis[con[x][i].FF]&&dfs(con[x][i].FF))return true;
	}
	return false;
}
int main()
{
	memset(ans,-1,sizeof(ans));
	geti(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		scanf("%s",t);
		s[0]-='A';
		s[1]-='A';
		s[2]-='A';
		t[0]-='A';
		x[i]=s[0]*900+s[1]*30+s[2];
		y[i]=s[0]*900+s[1]*30+t[0];
//		swap(x[i],y[i]);
//		cout<<x[i]<<" "<<y[i]<<endl;
		con[x[i]].PB(MP(y[i],i));
	}
/*	for(int i=1;i<=n;i++)
	{
		if(!vis[y[i]])
		{
			if(dfs(y[i]))
			{
				puts("NO");
				return 0;
			}
		}
	}*/
	for(int i=0;i<30000;i++)
	{
		int cnt=0;
		for(int j=0;j<con[i].size();j++)
		{
			if(ans[con[i][j].SS]==-1)
			{
				cnt++;
			}
		}
		if(cnt>1)
		{
			if(dfs(i))
			{
				puts("NO");
				return 0;
			}
		}
/*		if(cnt>1)
		{
			for(int j=0;j<con[i].size();j++)
			{
				if(mk[con[i][j].FF])continue;
				ans[con[i][j].SS]=con[i][j].FF;
				mk[con[i][j].FF]=1;
			}
		}*/
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==-1&&mk[y[i]]&&mk[x[i]])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==-1)ans[i]=x[i];
		putchar('A'+ans[i]/900);
		putchar('A'+(ans[i]/30)%30);
		putchar('A'+ans[i]%30);
		puts("");
	}
	return 0;
}