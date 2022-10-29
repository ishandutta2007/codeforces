#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2000005
using namespace std;
int i,j,m,n,p,k,Q[N],sum[N],P[N],start;
int a,b,c,d;
void Prt()
{
	 printf("-1\n");
	 exit(0);
}
int main()
{
   scanf("%d%d%d%d",&a,&b,&c,&d);
   if (abs(c-d)>1) Prt();
   if (c-d>0) start=4,a--; else 
     if (c-d<0) start=7,b--;
        else if (a!=c) start=4,a--;
        else start=7,b--;
   Q[0]=1; Q[1]=start; sum[1]=1; 
   for (i=2;;++i)
 {
 	  if (start==4) start=7,c--,b--; else start=4,d--,a--;
 	  Q[++Q[0]]=start; 
 	  sum[Q[0]]=1;
 	  if (!c&&!d) break;
 }
   if (a<0||b<0) Prt();
   for (i=1;;++i) if (Q[i]==4) break; sum[i]+=a;
   for (i=N-1;;--i) if (Q[i]==7) break; sum[i]+=b;
   for (i=1;i<N;++i)
     if (sum[i])
       for (j=1;j<=sum[i];++j) putchar(Q[i]+'0');
     else break;
}