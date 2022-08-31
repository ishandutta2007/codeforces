#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;
int n,p,w[100],q;
string x[70010];
char s[20];
map<int,int> f;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%s",&s);
	   x[i]=s;
	  }
	for(i=1;i<=n;i++)
	  for(j=0;j<=8;j++)
	    for(k=j,p=x[i][j]-'0'+1;k<=8;k++,p=p*10+x[i][k]-'0'+1)
	      {
		   l=f[p];
		   if(!l)
		     f[p]=i;
		   else if(l!=i)
		     f[p]=-1;
		  }
	for(i=1;i<=n;i++)
	  {
	   int u=10000,v=0;
	   for(j=0;j<=8;j++)
	     for(k=j,p=x[i][j]-'0'+1;k<=8 && k-j<u;k++,p=p*10+x[i][k]-'0'+1)
	       if(f[p]==i)
	         {
			  u=k-j;
			  v=p;
			 }
	   for(j=0;j<=u;j++)
	     {
		  v--;
		  w[++q]=v%10;
		  v/=10;
		 }
	   for(j=q;j>0;j--)
	     printf("%d",w[j]);
	   printf("\n");
	   q=0;
	  }
	return 0;
}