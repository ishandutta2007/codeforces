#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,a[300010],b[300010],x[2],y[2];
char s[10];
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,k=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d%s",&a[i],&s);
	   if(s[0]=='G')
	     {
	      b[i]=2;
	      k=1;
		 }
	   else if(s[0]=='R')
	     b[i]=0;
	   else
	     b[i]=1;
	  }
	if(!k)
	  {
	   k=2e9;
	   for(i=1;i<=n;i++)
	     {
		  if(x[b[i]])
		    p+=a[i]-x[b[i]];
		  x[b[i]]=a[i];
		  if(x[b[i]^1])
		    k=min(k,a[i]-x[b[i]^1]);
		 }
	  }
	else
	  {
	   for(i=1,k=0;i<=n;i++)
	     if(b[i]<2)
	       {
			if(!x[b[i]])
			  {
			   x[b[i]]=a[i];
			   if(k)
			     y[b[i]]=a[i]-k;
			  }
			else
			  {
			   y[b[i]]=max(y[b[i]],a[i]-x[b[i]]);
			   x[b[i]]=a[i];
			  }
		   }
		 else
		   {
			y[0]=max(y[0],a[i]-x[0]);
			y[1]=max(y[1],a[i]-x[1]);
			if(k)
			if(!x[0] || !x[1])
			  {
			   p+=a[i]-k;
			   if(x[0])
			     p+=a[i]-k-y[0];
			   if(x[1])
			     p+=a[i]-k-y[1];
			  }
			else
			  p+=3ll*(a[i]-k)-max(a[i]-k,y[0]+y[1]);
			k=a[i];
			x[0]=y[0]=x[1]=y[1]=0;
		   }
	   x[0]=x[1]=0;
	   for(i=1;i<=n;i++)
	     if(b[i]<2)
	       {
			if(!x[b[i]])
			  x[b[i]]=a[i];
		   }
		 else
		   {
			if(x[0])
			  p+=a[i]-x[0];
			if(x[1])
			  p+=a[i]-x[1];
			break;
		   }
	   x[0]=x[1]=0;
	   for(i=n;i>0;i--)
	     if(b[i]<2)
	       {
			if(!x[b[i]])
			  x[b[i]]=a[i];
		   }
		 else
		   {
			if(x[0])
			  p+=x[0]-a[i];
			if(x[1])
			  p+=x[1]-a[i];
			break;
		   }
	  }
	cout<<p;
	return 0;
}