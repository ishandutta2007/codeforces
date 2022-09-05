//while(true)rp++;
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
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
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

int n,d[400111],ans[400111],arc[400111];
vector<pair<int,int> >con[400111];
bool vis[400111];
void addedge(int x,int y,int id)
{
//	cout<<"addedge:"<<x<<"-"<<y<<endl;
	con[x].PB(MP(y,id));
	con[y].PB(MP(x,id));
	d[x]++;d[y]++;
}
void dfs(int x,int c)
{
//	cout<<"dfs:"<<x<<" "<<c<<endl;
	for(int &i=arc[x];i<con[x].size();i++)
	{
//		cout<<i<<":"<<con[x][i].FF<<endl;
		if(!vis[con[x][i].SS])
		{
			vis[con[x][i].SS]=1;
			ans[con[x][i].SS]=c;
			dfs(con[x][i].FF,c^1);
			return;
		}
	}
}
int main()
{
	geti(n);
	int x,y;
	for(int i=1;i<=n;i++)
	{
		getii(x,y);
		addedge(x,200000+y,i);
	}
	int last=0,id=n;
	for(int i=1;i<=400000;i++)
	{
		if(d[i]&1)
		{
			if(last!=0)
			{
				if(last<=200000&&i>200000)
					addedge(last,i,n+1);
				else if(i<=200000)
					addedge(last,400001,++id),addedge(i,400001,++id);
				else
					addedge(last,400002,++id),addedge(i,400002,++id);
				last=0;
			}
			else
			{
				last=i;
			}
		}
	}
	for(int i=1;i<=400002;i++)if(con[i].size()>0)dfs(i,0);
	for(int i=1;i<=n;i++)
	{
		if(ans[i])putchar('r');else putchar('b');
	}
	return 0;
}