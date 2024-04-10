#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=201;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N][N],b[N],c[N],d[N],ans[N],n;
int head[N],nex[N*N>>1],to[N*N>>1],cnt;
bitset<N>vis;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
bool check()
{
	memcpy(d+1,c+1,n<<2);
	for(int i=1;i<n;++i)vis[i]=0;
	int res=ans[1];
	for(int i=1;i<=n;++i)res^=i;
	for(int i=1;i<=cnt;++i)
	{
		int val=ans[i];
		for(int i=head[val];i;i=nex[i])
		{
			int w=to[i];
			if(vis[w])continue;
			vis[w]=1;
			int k,mx=-1;
			for(int j=1;j<=b[w];++j)
			{
				int t=a[w][j];
				if(!--d[t]&&c[t]>=mx)
				{
					mx=c[t];
					k=t;
				}
			}
			if(~mx)
			{
				ans[++cnt]=k;
				res^=k;
			}
			break;
		}
	}
	ans[++cnt]=res;
	return cnt==n;
}
void solve()
{
	n=read();
	memset(c+1,-1,n<<2);
	memset(head+1,0,n<<2);
	cnt=0;
	for(int i=1;i<n;++i)
	{
		b[i]=read();
		for(int j=1;j<=b[i];++j)
		{
			a[i][j]=read();
			++c[a[i][j]];
			add(a[i][j],i);
		}
	}
	for(int i=1;1;++i)
	{
		if(c[i])continue;
		cnt=1;
		ans[1]=i;
		if(check())break;
	}
	for(int i=n;i>=1;--i)write(ans[i],' ');
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}