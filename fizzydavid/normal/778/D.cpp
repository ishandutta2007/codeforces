//by yjz
#include<bits/stdc++.h>
using namespace std;
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
char id[256];
//U D L R
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
int n,m;
char s[55][55],t[55][55];
vector<pair<int,int> >cmd;
bool f[55][55];
int getst(int x,int y,int d)
{
	return f[x+dx[d]][y+dy[d]];
}
int dir[55][55];
bool check(int x,int y,int nx,int ny)
{
	if(x==nx)return s[x][y]=='L'&&s[x][y+1]=='R';
	else return s[x][y]=='U'&&s[x+1][y]=='D';
}
void rotate(int x,int y)
{
	cmd.PB(MP(x,y));
	if(s[x][y]=='U')
	{
		s[x][y]='L';
		s[x+1][y]='L';
		s[x][y+1]='R';
		s[x+1][y+1]='R';
	}
	else
	{
		s[x][y]='U';
		s[x+1][y]='D';
		s[x][y+1]='U';
		s[x+1][y+1]='D';
	}
}
void solve(int x,int y,int nx,int ny)
{
//	cout<<"solve:"<<x<<" "<<y<<" "<<nx<<" "<<ny<<endl;
//	system("pause");
	if(check(x,y,nx,ny))return;
	else
	{
		if(x==nx)
		{
			solve(x,y+1,nx+1,y);
		}
		else
		{
			solve(x+1,y,nx,y+1);
		}
		rotate(x,y);
	}
}
int main()
{
	id['U']=0;
	id['D']=1;
	id['L']=2;
	id['R']=3;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)scanf("%s",t[i]+1);
	for(int i=0;i<=n;i++)f[i][0]=1;
	for(int i=0;i<=m;i++)f[0][i]=1;
	for(int _=1;_<=n*m/2;_++)
	{
		bool ok=0;
		for(int i=1;i<=n&&!ok;i++)
		{
			for(int j=1;j<=m&&!ok;j++)
			{
				if(f[i][j])continue;
				if(getst(i,j,0)&&getst(i,j,2))
				{
					if(t[i][j]=='U'&&getst(i+1,j,2))
					{
						ok=1;
						solve(i,j,i+1,j);
						f[i][j]=1;
						f[i+1][j]=1;
					}
					else if(t[i][j]=='L'&&getst(i,j+1,0))
					{
						ok=1;
						solve(i,j,i,j+1);
						f[i][j]=1;
						f[i][j+1]=1;
					}
				}
			}
		}
//		for(int i=1;i<=n;i++)printf("%s\n",s[i]+1);
//		puts("");
	}
	putsi(cmd.size());
	for(int i=0;i<cmd.size();i++)putsii(cmd[i].FF,cmd[i].SS);
	return 0;
}