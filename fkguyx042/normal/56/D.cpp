#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1005 

using namespace std;
int i,j,m,n,p,k,f[N][N],lastx[N][N],lasty[N][N],A[N],B[N],tot;
char c[N],s[N];
int main()
{
	 scanf("%s",c); int len=strlen(c); for (i=len;i;--i) c[i]=c[i-1];
	 scanf("%s",s); int Len=strlen(s); for (i=Len;i;--i) s[i]=s[i-1];
	 memset(f,60,sizeof(f));
	 f[0][0]=0;
	 for (i=0;i<=len;++i)
	    for (j=0;j<=Len;++j)
	      {
	      	   if (f[i+1][j]>f[i][j]+1)
	      	   {
	      	   	  f[i+1][j]=f[i][j]+1;
	      	   	  lastx[i+1][j]=i;
          	   	  lasty[i+1][j]=j;
          	   }
          	   if (f[i][j+1]>f[i][j]+1)
          	   {
          	   	  f[i][j+1]=f[i][j]+1;
          	   	  lastx[i][j+1]=i;
          	   	  lasty[i][j+1]=j;
          	   }
          	   if (c[i+1]==s[j+1])
          	   {
          	   	  if (f[i+1][j+1]>f[i][j])
          	   	  {  
          	   	      f[i+1][j+1]=f[i][j];
          	   	      lastx[i+1][j+1]=i;
          	   	      lasty[i+1][j+1]=j;
          	   	  }
          	   }
          	   else 
          	   {
          	   	  if (f[i+1][j+1]>f[i][j]+1)
          	   	  {
          	   	  	  f[i+1][j+1]=f[i][j]+1;
          	   	  	  lastx[i+1][j+1]=i;
          	   	  	  lasty[i+1][j+1]=j;
          	   	  }
          	   }
          }
        printf("%d\n",f[len][Len]);
        i=len,j=Len;
        while (i||j)
        {
        	 if (lastx[i][j]==i-1&&lasty[i][j]==j-1)
        	 {
        	 	   if (f[i-1][j-1]==f[i][j]-1) A[++tot]=3,B[tot]=j;
        	 }
        	 else 
        	 if (lastx[i][j]==i-1) A[++tot]=2,B[tot]=j+1;
        	 else A[++tot]=1,B[tot]=j;
        	 int ix=lastx[i][j],jx=lasty[i][j];
        	 i=ix; j=jx;
       }
       for (i=tot;i;--i)
         if (A[i]==1) printf("INSERT %d %c\n",B[i],s[B[i]]);
         else  if (A[i]==2) printf("DELETE %d\n",B[i]);
         else printf("REPLACE %d %c\n",B[i],s[B[i]]);
}