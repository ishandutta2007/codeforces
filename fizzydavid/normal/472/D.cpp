//while(true)rp++;
//cin 
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
#define input1(x) x=getnum()
#define input2(x,y) input1(x),y=getnum()
#define input3(x,y,z) input2(x,y),z=getnum()
#define input4(x,y,z,w) input3(x,y,z),w=getnum()
#define output1(x) putnum(x)
#define output2(x,y) output1(x),putnum(y)
#define output3(x,y,z) output2(x,y),putnum(z)
#define output4(x,y,z,w) output3(x,y,z),putnum(w)
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

int n,dis[2011][2011],p[2011],ans[2011][2011];
vector<pair<int,pair<int,int> > >edges;
int gf(int x)
{
	if(x==p[x])return x;
	return p[x]=gf(p[x]);
}
bool un(int x,int y)
{
	x=gf(x);y=gf(y);
	if(x==y)return true;
	p[x]=y;
	return false;
}
vector<pair<int,int> >con[2011];
void dfs(int o,int x,int pre)
{
	for(int i=0;i<con[x].size();i++)
		if(con[x][i].FF!=pre)
			ans[o][con[x][i].FF]=ans[o][x]+con[x][i].SS,dfs(o,con[x][i].FF,x);
}
int main()
{
	input1(n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			input1(dis[i][j]);
			if(i!=j)
			{
				edges.PB(MP(dis[i][j],MP(i,j)));
			}
		}
	}
	bool ok=1;
	for(int i=1;i<=n;i++)p[i]=i;
	sort(edges.begin(),edges.end());
	for(int i=0;i<edges.size();i++)
	{
		int x=edges[i].SS.FF,y=edges[i].SS.SS,d=edges[i].FF;
		if(un(x,y))continue;
		else
		{
			con[x].PB(MP(y,d));
			con[y].PB(MP(x,d));
			if(d==0)ok=0;
		}
	}
	for(int i=1;i<=n;i++)dfs(i,i,-1);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ok&=(dis[i][j]==ans[i][j]);
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}