#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 505
#define M 4005

const int Mo=(int)1e9+7; 

using namespace std;
char c[N][N];
int i,j,m,n,p,k,f[2][N][N],step,now,last;
void jia(int &x,int y)
{
	 x+=y;
	 if (x>=Mo) x-=Mo;
}
int main()
{
    memset(f,0,sizeof(f));
    scanf("%d%d",&n,&m);
     f[0][0][n-1]=1;
    for (i=0;i<n;++i) scanf("%s",c[i]);
    if (c[0][0]!=c[n-1][m-1]) { puts("0"); return 0; }
    int lim=(n+m-2)/2;
    for (step=0;step<lim;++step)
    {
    	  now^=1; last=now^1;
    	  memset(f[now],0,sizeof(f[now]));
    	   for (j=0;j<n;++j)
    	      for (k=0;k<n;++k)
    	        if (f[last][j][k])
    	        {
    	        	  int rx=n+m-2-k-step;
    	        	  if (j<n-1)
    	        	  {
    	        	  	  if (k>0)
    	        	  	  	  if (c[j+1][step-j]==c[k-1][rx]) jia(f[now][j+1][k-1],f[last][j][k]);
    	        	  	  if (rx>0)
    	        	  	     if (c[j+1][step-j]==c[k][rx-1]) jia(f[now][j+1][k],f[last][j][k]);
    	        	  }
    	        	  if (step-j<m-1)
    	        	  {
    	        	  	  if (k>0)
    	        	  	      if (c[j][step-j+1]==c[k-1][rx]) jia(f[now][j][k-1],f[last][j][k]);
    	        	  	   if (step-k<m-1)
    	        	  	     if (c[j][step-j+1]==c[k][rx-1]) jia(f[now][j][k],f[last][j][k]);
    	        	  
					  }
				}
	}
	int ans=0;
	for (i=0;i<n;++i) jia(ans,f[now][i][i]);  
    if ((n+m-1)%2==0)
      for (i=0;i<n-1;++i) jia(ans,f[now][i][i+1]);
    printf("%d\n",ans);
}