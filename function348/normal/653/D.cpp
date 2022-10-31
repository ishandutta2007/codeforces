#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define CL(a,b) memset(a,b,sizeof(a))
using namespace std;
struct Edge{int y,z,ne;};
const int N=1000,inf=2100000000;
int n,m,k,num,S,T;
queue<int>Q;
Edge e[N*10];int last[N];
int h[N];
int x[N],y[N],z[N];
inline void add(int x,int y,int z)
{
    e[++num].y=y;e[num].z=z;e[num].ne=last[x];last[x]=num;
    e[++num].y=x;e[num].z=0;e[num].ne=last[y];last[y]=num;
}
inline int bfs()
{
    while (!Q.empty()) Q.pop();
    CL(h,0);h[S]=1;
    Q.push(S);
    while (!Q.empty())
    {
        int now=Q.front();Q.pop();
        for (int j=last[now];j;j=e[j].ne)
        if (e[j].z&&h[e[j].y]==0)
        {
            h[e[j].y]=h[now]+1;
            Q.push(e[j].y);
            if (e[j].y==T) return 1;
        }
    }
    return 0;
}
int dfs(int i,int low)
{
    if (i==T) return low;
    int ret=0;
    for (int j=last[i];j;j=e[j].ne)
    if (e[j].z&&h[e[j].y]==h[i]+1)
    {
        int tmp=dfs(e[j].y,min(low,e[j].z));
        ret+=tmp;low-=tmp;
        e[j].z-=tmp;e[j^1].z+=tmp;
        if (low==0) break;
    }
    if (ret==0) h[i]=-1;
    return ret;
}
int check(double mid)
{
	num=1;S=1,T=n;
	for (int i=1;i<=n;i++) last[i]=0;
	for (int i=1;i<=m;i++) 
	{
		int t;
		if (z[i]/mid<inf) t=z[i]/mid;else t=k;
		add(x[i],y[i],t);
	}
	int res=0;
	while (bfs()) 
	{
		res+=dfs(S,inf);
		if (res>=k) break;
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	double eps=1e-7;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	double l=0,r=1000000;
	while (l+eps/k<r&&r-l>eps*l)
	{
		double mid=(l+r)/2;
		if (check(mid)>=k) l=mid;else r=mid;
	}
	printf("%.8lf\n",l*k);
	return 0;
}