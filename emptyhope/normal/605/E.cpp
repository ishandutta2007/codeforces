#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define N 1005
int n;
long double p[N][N],dis[N],rest[N];
bool vis[N];

void work()
{
	// rest[j]: 
	//  dp  
	double x=1e18; int id;
	For(i,1,n)
		if(!vis[i] && (dis[i]+rest[i])/(1-rest[i])<=x)
			x=(dis[i]+rest[i])/(1-rest[i]),id=i;
	vis[id]=1;
	dis[id]=(dis[id]+rest[id])/(1-rest[id]);
	if(id==1){
		printf("%.15lf\n",(double)dis[1]);
		exit(0);
	}
	For(i,1,n)
		if(!vis[i])
			dis[i]+=rest[i]*p[i][id]*(dis[id]+1),
			rest[i]*=(1-p[i][id]);
}

signed main()
{
	n=read();
	For(i,1,n)For(j,1,n)p[i][j]=0.01*read();
	For(i,1,n-1)rest[i]=1;
	For(i,1,n)work();
    return 0;
}