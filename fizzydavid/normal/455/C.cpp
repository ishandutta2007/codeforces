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
const int maxn=300111;
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

int n,m,q,c[maxn],d[maxn],dis[maxn],tmx,tv;
vector<int>con[maxn];
void dfs(int x,int dis,int pre)
{
	if(dis>tmx)
		tmx=dis,tv=x;
	for(int i=0;i<con[x].size();i++)
		if(con[x][i]!=pre)
			dfs(con[x][i],dis+1,x);
}
int gf(int x)
{
	if(c[x]==x)
		return x;
	return c[x]=gf(c[x]);
}
int main()
{
	input3(n,m,q);
	for(int i=1;i<=n;i++)
		c[i]=i;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		input2(x,y);
		con[x].PB(y);
		con[y].PB(x);
		c[gf(x)]=gf(y);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==i)
		{
			tmx=0;tv=0;
			dfs(i,0,-1);
			tmx=0;
			dfs(tv,0,-1);
			d[gf(i)]=tmx;
		}
	}
	int op;
	while(q--)
	{
		input2(op,x);
		if(op==2)
		{
			input1(y);
			x=gf(x);y=gf(y);
			if(x==y)
				continue;
			c[x]=y;
			d[y]=max(d[x],max(d[y],(d[x]+1)/2+(d[y]+1)/2+1));
		}
		else
			putnum(d[gf(x)]),putendl();
	}
	return 0;
}
/*
6 0 6
2 1 2
2 3 4
2 5 6
2 3 2
2 5 3
1 1

*/