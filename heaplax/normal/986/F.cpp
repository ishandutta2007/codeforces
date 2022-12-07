#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 33333333
#define M 3000001
#define INF 1ll<<60
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
map<int,int> s;
int cnt,T,p[N/10],m,num[51],divisor[51];
bool vis[N],ans[N];
vector<pair<int,int>> ask[51];
void init()
{
	for(int i=2;i<N;++i)
	{
		if(!vis[i])
			p[++cnt]=i;
		for(int j=1,k;(k=i*p[j])<N;++j)
		{
			vis[k]=1;
			if(i%p[j]==0)break;
		}
	}
}
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int t=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return t;
}
namespace dij
{
	int cnt,head[M],nxt[M],to[M],w[M],dis[M],n;
	struct node
	{
		int a,b;
		node(int _a,int _b):a(_a),b(_b){}
		bool operator < (const node &i)const
		{
			return b>i.b;
		}
	};
	priority_queue<node> que;
	void add(int u,int v,int c)
	{
		nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,w[cnt]=c;
	}
	void main()
	{
		for(int i=1;i<n;++i)dis[i]=INF;
		que.push(node(0,0));
		do
		{
			int u=que.top().a;que.pop();
			for(int i=head[u],v;i;i=nxt[i])
				if(dis[u]+w[i]<dis[v=to[i]])
					que.push(node(v,dis[v]=dis[u]+w[i]));
			while(!que.empty() && dis[que.top().a]!=que.top().b)que.pop();
		}while(!que.empty());

	}
	void clear()
	{
		cnt=0;
		for(int i=0;i<n;++i)
			head[i]=0;
		n=0;
	}
}
main()
{
	init();
	re(T);
	for(int i=1,n,k;i<=T;++i)
	{
		re(n),re(k);
		if(k==1)continue;
		if(!s[k])
		{
			s[k]=++m;
			num[m]=k;
		}
		ask[s[k]].push_back(make_pair(n,i));
	}
	for(int i=1;i<=m;++i)
	{
		int n=0;
		for(int j=1;j<=cnt;++j)
			while(num[i]%p[j]==0)
				divisor[++n]=p[j],num[i]/=p[j];
		if(num[i]>1)divisor[++n]=num[i];
		if(n==1)
		{
			for(auto j:ask[i])
				ans[j.second]=!(j.first%divisor[1]);
			continue;
		}
		if(n==2)
		{
			int a=divisor[1],b=divisor[2];
			int x,y;
			int d=exgcd(a,b,x,y);
			y%=divisor[1];if(y<0)y+=divisor[1];
			for(auto j:ask[i])
			{
				if(j.first%d)continue;
				int z=(y*(j.first%divisor[1])%divisor[1])*divisor[2];
				ans[j.second]=z<=j.first;
			}
			continue;
		}
		for(int j=2;j<=n;++j)
			for(int k=0;k<divisor[1];++k)
				dij::add(k,(k+divisor[j])%divisor[1],divisor[j]);
		dij::n=divisor[1];
		dij::main();
		for(auto j:ask[i])
			ans[j.second]=j.first>=dij::dis[j.first%divisor[1]];
		dij::clear();
	}
	for(int i=1;i<=T;++i)
		puts(ans[i]?"YES":"NO");
}
/*
1
209003408561347 606910722826711

*/