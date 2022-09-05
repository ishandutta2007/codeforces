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
int n,q,f[300111],nxt[300111];
vector<int>v[300111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void un(int x)
{
	int y=x-1;
	x=gf(x);y=gf(y);
	f[x]=y;
	nxt[y]=max(nxt[y],nxt[x]);
}
bool read[300111];
int main()
{
	for(int i=0;i<=300100;i++)f[i]=i,nxt[i]=i+1;
	getii(n,q);
	int tot=0,ans=0;
	for(int i=1;i<=q;i++)
	{
		int cmd,x;
		getii(cmd,x);
		if(cmd==1)
		{
			tot++;
			v[x].PB(tot);
		}
		else if(cmd==2)
		{
			for(int j=0;j<v[x].size();j++)
			{
				if(read[v[x][j]])continue;
				un(v[x][j]);
				read[v[x][j]]=1;
				ans++;
			}
			v[x].clear();
		}
		else if(cmd==3)
		{
			for(int j=1;j<=x;j=nxt[gf(j)])
			{
				if(!read[j])
				{
					read[j]=1;
					un(j);
					ans++;
				}
			}
		}
		putsi(tot-ans);
	}
	return 0;
}