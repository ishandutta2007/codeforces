#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2000005

int i,n,x,P[N+5],ans;

int main()
{
	 scanf("%d",&n);
	 for (;n--;) scanf("%d",&x),P[x]++;
	 for (i=0;i<N;P[i+1]+=P[i]>>1,++i) ans+=P[i]&1;
	 printf("%d\n",ans);
}