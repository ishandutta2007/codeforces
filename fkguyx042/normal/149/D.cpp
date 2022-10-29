#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 705
#define M 205
#define seed 23333

using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,len,reg[N][N],ans;
int f[N][N][3][3];
char c[N];
void jia(int &x,int y)
{
	 x+=y;
	 if (x>=Mo) x-=Mo;
}
void dfs(int l,int r)
{
	  int i,j,k,lx;
	 if (l+1==r) f[l][r][0][1]=f[l][r][0][2]=f[l][r][1][0]=f[l][r][2][0]=1;
	 else 
	 {
	 	  if (reg[l+1][r-1]) 
	 	  {
	 	  	   dfs(l+1,r-1);
	 	  	   for (i=0;i<3;++i)
	 	  	       for (j=0;j<3;++j)
	 	  	          if ((i==0&&j!=0)||(i!=0&&j==0))
	 	  	             for (k=0;k<3;++k)
							    for (lx=0;lx<3;++lx)
							         if ((k!=i||!k)&&(lx!=j||!lx)) jia(f[l][r][i][j],f[l+1][r-1][k][lx]);
	 	  }
	 	  else 
	 	  {
	 	  	  for (i=l;i<r;++i)
	 	  	  if (reg[l][i]&&reg[i+1][r]) break;
	 	  	  dfs(l,i); dfs(i+1,r); int id=i;
	 	  	  for (i=0;i<3;++i)
	 	  	     for (j=0;j<3;++j)
	 	  	         for (k=0;k<3;++k)
	 	  	              for (lx=0;lx<3;++lx)
	 	  	                 if (lx!=k||!lx)
	 	  	                    jia(f[l][r][i][j],1ll*f[l][id][i][k]*f[id+1][r][lx][j]%Mo);
	 	  }
	 }
}
int main()
{
	  scanf("%s",c); 
	  len=strlen(c);
	  for (i=len;i;--i) c[i]=c[i-1];
	  for (i=1;i<=len;++i)
	  {
	  	    k=0;
	  	    for (j=i;j<=len;++j)
	  	     {
	  	     	   if (c[j]=='(') ++k; else --k;
	  	     	   if (k<0) break;
	  	     	   if (k==0) reg[i][j]=1;
	  	     }
     }
     dfs(1,len);
     for (i=0;i<3;++i)
        for (j=0;j<3;++j) (ans+=f[1][len][i][j])%=Mo;
     printf("%d\n",ans);
}