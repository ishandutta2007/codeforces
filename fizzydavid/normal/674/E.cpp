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
int q,p[500111],tot;
double dp[500111][42],sum[500111][42];
void del(int x,int y)//remove son y from x
{
	double t=1.0/2;
	for(int i=0;i<40;i++)
	{
		sum[x][i]/=t;
		t+=dp[y][i]/2;
	}
}
void add(int x,int y)//add son y to x
{
	double t=1.0/2;
	for(int i=0;i<40;i++)
	{
		sum[x][i]*=t;
		t+=dp[y][i]/2;
	}
}
void update(int x)
{
	dp[x][0]=sum[x][0];
	for(int i=1;i<40;i++)dp[x][i]=sum[x][i]-sum[x][i-1];
}
int main()
{
	tot++;
	p[1]=-1;
	for(int i=0;i<40;i++)sum[1][i]=1;
	update(1);
	geti(q);
	while(q--)
	{
		int type,x;
		getii(type,x);
		if(type==1)
		{
			int tx=x;
			tot++;
			p[tot]=x;
			for(int i=0;i<40;i++)sum[tot][i]=1;
			update(tot);
			x=tx;
			for(int i=1;p[x]!=-1&&i<40;i++,x=p[x])
			{
				del(p[x],x);
			}
			x=tx;
			add(x,tot);
			update(x);
			for(int i=1;p[x]!=-1&&i<40;i++,x=p[x])
			{
				add(p[x],x);
				update(p[x]);
			}
		}
		else
		{
			double ans=0;
			for(int i=1;i<40;i++)ans+=dp[x][i]*i;
			printf("%.8lf\n",ans);
		}
//		for(int i=1;i<=tot;i++)see(i);
	}
	return 0;
}