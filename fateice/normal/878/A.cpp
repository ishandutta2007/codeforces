#include<bits/stdc++.h>
using namespace std;
int n,a[15],b,c[15],m;
char s[10];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	for(i=0;i<10;i++)
	  a[i]=c[i]=2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%s%d",&s,&k);
	   if(s[0]=='^')
	     if(!b)
	       {
	        b=k;
	        for(j=0;j<10;j++)
	          {
			   a[j]=c[j];
			   c[j]=2;
			  }
		   }
	     else
	       {
			b^=k;
			for(j=0;j<10;j++)
			  if(c[j]!=2 && k&(1<<j))
			    c[j]^=1;
		   }
	   else if(s[0]=='&')
	     {
		  for(j=0;j<10;j++)
		    if(!(k&(1<<j)))
		      c[j]=0;
		 }
	   else
	     {
		  for(j=0;j<10;j++)
		    if(k&(1<<j))
		      c[j]=1;
		 }
	  }
	printf("5\n");
	for(i=0,k=0;i<10;i++)
	  if(a[i]==1)
	    k+=1<<i;
	printf("| %d\n",k);
	for(i=0,k=0;i<10;i++)
	  if(a[i]==0)
	    k+=1<<i;
	printf("& %d\n",1023-k);
	printf("^ %d\n",b);
	for(i=0,k=0;i<10;i++)
	  if(c[i]==1)
	    k+=1<<i;
	printf("| %d\n",k);
	for(i=0,k=0;i<10;i++)
	  if(c[i]==0)
	    k+=1<<i;
	printf("& %d\n",1023-k);
	return 0;
}