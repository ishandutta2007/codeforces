#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=210;
int G[N][N],n,m,dd[N][N],d[N];
void DFS(int u)
{
	forinc(v,0,n) if(G[u][v]&&!dd[u][v])
	{
		dd[u][v]=dd[v][u]=1;
		DFS(v);
		if(u&&v) cout<<u<<" "<<v<<endl;
	}
}

int main()
{
    //freopen("723E.inp","r",stdin);
	forinc(cs,1,in)
    {
		n=in,m=in;
		reset(dd,0);reset(G,0);reset(d,0);
		while(m--)
		{
			int u=in,v=in;
			d[u]++;d[v]++;
			G[u][v]=1;
			G[v][u]=1;
		}
		int ans=0;
		forinc(i,1,n)
		{
			if(d[i]%2==0) ++ans;
			else G[i][0]=G[0][i]=1;
		}
		cout<<ans<<endl;
		forinc(i,0,n) DFS(i);
	}
}