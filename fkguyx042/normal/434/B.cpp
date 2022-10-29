#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,q,up[1005][1005],down[1005][1005],left[1005][1005],right[1005][1005],a[1005][1005];
int type,x,y,ans;
int main()
{   scanf("%d%d%d",&n,&m,&q);
   for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)  scanf("%d",&a[i][j]);
   for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
	    if (a[i][j]) left[i][j]=left[i][j-1]+1,up[i][j]=up[i-1][j]+1;
	    else left[i][j]=up[i][j]=0;
   for (i=n;i;i--)
     for (j=m;j;j--)
        if (a[i][j]) right[i][j]=right[i][j+1]+1,down[i][j]=down[i+1][j]+1;
        else right[i][j]=down[i][j]=0;
  for (;q--;)
{
	 scanf("%d%d%d",&type,&x,&y);
	 if (type==1)
	{    a[x][y]^=1;
	     for (j=1;j<=m;j++)
	       if (a[x][j]) left[x][j]=left[x][j-1]+1; else left[x][j]=0;
	     for (j=m;j;j--)
	       if (a[x][j]) right[x][j]=right[x][j+1]+1; else right[x][j]=0;
	     for (j=1;j<=n;j++)
	       if (a[j][y]) up[j][y]=up[j-1][y]+1; else up[j][y]=0;
	     for (j=n;j;j--)
	       if (a[j][y]) down[j][y]=down[j+1][y]+1; else down[j][y]=0;
	}
	else 
	  {     ans=0;   
	        int L=10000,R=10000;
	           for (i=1;i<=up[x][y];i++)
	          {  L=min(L,left[x-i+1][y]);
	             R=min(R,right[x-i+1][y]);
	             ans=max(ans,(R+L-1)*i);
	          }
	          L=10000; R=10000;
	          for (i=1;i<=down[x][y];i++)
	          {  L=min(L,left[x+i-1][y]);
	             R=min(R,right[x+i-1][y]);
	             ans=max(ans,(R+L-1)*i);
	          }
	          L=10000; R=10000;
	          for (i=1;i<=left[x][y];i++)
	          {   
	               L=min(L,up[x][y-i+1]);
	               R=min(R,down[x][y-i+1]);
	               ans=max(ans,(R+L-1)*i);
	          }
	          L=10000; R=10000;
	          for (i=1;i<=right[x][y];i++)
	          {  
	               L=min(L,up[x][y+i-1]);
	               R=min(R,down[x][y+i-1]);
	               ans=max(ans,(R+L-1)*i);
	          }
	          printf("%d\n",ans);
     }
}
}