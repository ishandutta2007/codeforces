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
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n;
double p[1001][1001],q[1001],last[1001];
bool use[1001];
int main()
{
	re(n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%lf",&p[i][j]),p[i][j]/=100;
	for(int i=1;i<n;++i)last[i]=q[i]=1;
	while(1)
	{
		int num=0;
		double mn=1e100;
		for(int i=1;i<=n;++i)
			if(!use[i] && (i==n || (last[i]!=1 && q[i]/(1-last[i])<mn)))
				num=i,mn=q[i]/(1-last[i]);
		if(!num)break;
//		cerr<<num<<endl;
//		cerr<<mn<<endl;
		use[num]=1;
		q[num]=mn;
		for(int i=1;i<=n;++i)
			if(!use[i])
				q[i]+=last[i]*p[i][num]*mn,last[i]*=(1-p[i][num]);
//		for(int i=1;i<=n;++i)
//			printf("%.3f %.3f\n",q[i],last[i]);
	}
	printf("%.15f\n",q[1]);
}