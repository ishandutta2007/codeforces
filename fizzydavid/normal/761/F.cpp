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
int n,m,k;
int lx[300111],ly[300111],rx[300111],ry[300111],ch[300111];
char g[1011][1011];
int cnt[1011][30];
ll cost[1011][1011][30];
void solve(int r)
{
	for(int i=1;i<=m;i++)
	{
//		cout<<r<<" "<<i<<" "<<endl;
		int tcnt[30];
		for(int j=0;j<27;j++)
		{
			cnt[i][j]+=cnt[i-1][j];
			tcnt[j]=cnt[i][j];
		}
		tcnt[0]=k;
		for(int j=1;j<27;j++)tcnt[0]-=tcnt[j];
		tcnt[g[r][i]-'a'+1]+=tcnt[0];
		int sum=0,sum2=0;
		for(int j=1;j<27;j++)
		{
			sum2+=sum;
			cost[r][i][j]+=sum2;
			sum+=tcnt[j];
		}
		sum=0;sum2=0;
		for(int j=26;j>0;j--)
		{
			sum2+=sum;
			cost[r][i][j]+=sum2;
			sum+=tcnt[j];
		}
		cost[r][i][0]=cost[r][i][g[r][i]-'a'+1];
	}
/*	cout<<"cost="<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<27;j++)
		{
			cout<<cost[r][i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=m;i++)for(int j=0;j<27;j++)cost[r][i][j]+=cost[r][i-1][j];
	for(int i=1;i<=m;i++)for(int j=0;j<27;j++)cost[r][i][j]+=cost[r-1][i][j];
	
}
ll get(int i,int c)
{
	return cost[rx[i]][ry[i]][c]-cost[lx[i]-1][ry[i]][c]-cost[rx[i]][ly[i]-1][c]+cost[lx[i]-1][ly[i]-1][c];
}
int main()
{
	getiii(n,m,k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			g[i][j]=mygetchar();
		}
	}
	for(int i=1;i<=k;i++)
	{
		getii(lx[i],ly[i]);
		getii(rx[i],ry[i]);
		ch[i]=mygetchar();
		ch[i]-='a';
		ch[i]++;
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<"i="<<i<<endl;
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=k;j++)
		{
			if(lx[j]<=i&&i<=rx[j])
			{
				cnt[ly[j]][ch[j]]++;
				cnt[ry[j]+1][ch[j]]--;
			}
		}
/*		for(int j=1;j<=m;j++)
		{
			for(int t=1;t<27;t++)
			{
				cout<<cnt[j][t]<<" ";
			}cout<<endl;
		}*/
		solve(i);
	}
	ll mn=1ll<<60;
	for(int i=1;i<=k;i++)
	{
		ll tmp=cost[n][m][0];
		tmp-=get(i,0);
		tmp+=get(i,ch[i]);
		mn=min(mn,tmp);
//		cout<<"tmp="<<tmp<<endl;
	}
	cout<<mn<<endl;
	return 0;
}