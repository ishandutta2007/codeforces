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
const ll Lbig=2e18;
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
int n,a[5011];
int tabr[5011],tabc[5011][5011],dp[5011][5011],id0[5011],id1[5011],id2[5011];
int mxr[7],mxc[5011][7];
map<pair<int,int>,int> mp;
map<int,int> id;
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(a[i]),id[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		id0[i]=id[a[i]];
		id1[i]=id[a[i]+1];
		id2[i]=id[a[i]-1];
	}
	int mx=0;
	for(int i=0;i<=n;i++)
	{
		memset(mxr,0,sizeof(mxr));
		memset(tabr,0,sizeof(tabr));
		for(int j=0;j<=n;j++)
		{
			if(i==j)continue;
			int &v=dp[i][j];
			v=(i>0)+(j>0);
			if(i>j)v=dp[j][i];
			else
			{
				v=max(v,mxr[a[j]%7]+1);
				if(id1[j])v=max(v,tabr[id1[j]]+1);
				if(id2[j])v=max(v,tabr[id2[j]]+1);
			}
			if(j==0)for(int t=0;t<7;t++)mxr[t]=max(mxr[t],v);
			else mxr[a[j]%7]=max(mxr[a[j]%7],v);
			tabr[id0[j]]=max(tabr[id0[j]],v);
			mx=max(mx,v);
		}
	}
	cout<<mx<<endl;
	return 0;
}