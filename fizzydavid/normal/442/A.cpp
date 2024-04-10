//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
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
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
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
bool a[5][5],b[5][5];
int n;
bool f1[5],f2[5];
bool dfs()
{
	int cnt=0,x,y;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cnt+=b[i][j];
	if(cnt<=1)return true;
	for(int i=0;i<5;i++)
	{
		if(f1[i])
		{
			cnt=0;
			for(int j=0;j<5;j++)if(b[i][j])cnt++,y=j;
			if(cnt==1)
			{
				b[i][y]=0;
				return dfs();
			}
		}
	}
	for(int i=0;i<5;i++)
	{
		if(f2[i])
		{
			cnt=0;
			for(int j=0;j<5;j++)if(b[j][i])cnt++,x=j;
			if(cnt==1)
			{
				b[x][i]=0;
				return dfs();
			}
		}
	}
	return false;
}
int main()
{
	geti(n);
	while(n--)
	{
		string s;
		cin>>s;
		int x,y;
		if(s[0]=='R')x=0;
		else if(s[0]=='G')x=1;
		else if(s[0]=='B')x=2;
		else if(s[0]=='Y')x=3;
		else x=4;
		y=s[1]-'1';
		a[x][y]=1;
	}
	int ans=INF;
	for(int i=0;i<(1<<10);i++)
	{
		int cnt=0;
		for(int j=0;j<10;j++)cnt+=(i>>j)&1;
		for(int j=0;j<5;j++)f1[j]=(i>>j)&1;
		for(int j=0;j<5;j++)f2[j]=(i>>j>>5)&1;
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				b[j][k]=!(f1[j]&&f2[k])&&a[j][k];
			}
		}
		if(dfs())ans=min(ans,cnt);
	}
	putsi(ans);
	return 0;
}