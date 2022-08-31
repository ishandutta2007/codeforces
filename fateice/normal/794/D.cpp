#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<map>
#include<vector>
#define L long long
using namespace std;
int n,m,p,q1,q2,t,a[300010],y[300010],w,u;
L x[300010];
map<L,int> f,g;
vector<int> r[300010];
inline bool cmp(int a,int b)
{
    return x[a]<x[b];
}
inline int power(int a,int b,int q)
{
    if(!b)
      return 1;
    int c=power(a,b>>1,q);
    c=(L)c*c%q;
    if(b&1)
      c=(L)c*a%q;
    return c;
}
inline L ran()
{
    return ((L)rand()<<45)+((L)rand()<<30)+(rand()<<15)+rand();
}
inline void dfs(int i)
{
    int j;
    u--;
    g[x[i]]=++w;
    for(j=0;j<r[i].size();j++)
      if(!g[x[r[i][j]]])
        dfs(r[i][j]);
}
inline bool check(int p)
{
    int i;
    for(i=2;i*i<=p;i++)
      if(p%i==0)
        return 0;
    return 1;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	srand(time(0));
	ran();
	ran();
	ran();
	for(q1=ran()%1000000000+100000000;!check(q1);q1++);
	for(q2=ran()%1000000000+100000000;!check(q2);q2++);
	for(p=ran()%1000000+100000;!check(p);p++);
	for(t=ran()%1000000+100000;!check(t);t++);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  {
       x[i]=power(p,i^t,q1);
       y[i]=power(p,i^t,q2);
      }
	for(i=1;i<=m;i++)
	  {
       scanf("%d%d",&j,&k);
       x[j]=(x[j]+power(p,k^t,q1))%q1;
       y[j]=(y[j]+power(p,k^t,q2))%q2;
       x[k]=(x[k]+power(p,j^t,q1))%q1;
       y[k]=(y[k]+power(p,j^t,q2))%q2;
       r[j].push_back(k);
       r[k].push_back(j);
      }
    for(i=1;i<=n;i++)
      {
       x[i]=x[i]*2000000000+y[i];
       a[i]=i;
      }
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;i++)
      if(i==1 || x[a[i]]!=x[a[i-1]])
        {
         for(j=0,k=0;j<r[a[i]].size();j++)
           if(x[r[a[i]][j]]!=x[a[i]] && !g[x[r[a[i]][j]]])
             {
              g[x[r[a[i]][j]]]=1;
              k++;
             }
         g.clear();
         f[x[a[i]]]=k;
         u++;
        }
    for(i=1;i<=n;i++)
      if(f[x[i]]>2)
        {
         u=1;
         break;
        }
      else if(f[x[i]]<=1 && !g[x[i]])
        dfs(i);
    if(u)
      printf("NO\n");
    else
      {
       printf("YES\n");
       for(i=1;i<=n;i++)
         printf("%d ",g[x[i]]);
      }
	return 0;
}