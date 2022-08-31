#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,q,x[1000010],a[1000010],f[1000010],g[1000010],h[1000010];
char s[1000010];
inline int ran()
{
	return ((rand()<<15)+rand())%1000000000;
}
inline int get(int l,int r)
{
	return ((x[r]-(L)x[l-1]*a[r-l+1])%q+q)%q;
}
inline void get(int l,int r,int f[])
{
	int i;
	f[0]=r-l+1;
	for(i=r;i>=l;i--)
	  f[r-i+1]=s[i-1]-'0';
}
inline void check(int l,int r)
{
	if(l>0 && l<r-1 && (s[0]!='0' || l==1) && (s[l]!='0' || r==l+2) && (s[r-1]!='0' || r==n) && (get(1,l)+get(l+1,r-1))%q==get(r,n))
	  {
	   get(1,l,f);
	   get(l+1,r-1,g);
	   get(r,n,h);
	   int i;
	   for(i=f[0]+1;i<=g[0];i++)
	     f[i]=0;
	   f[0]=max(f[0],g[0]);
	   f[f[0]+1]=0;
	   for(i=1;i<=g[0];i++)
	     {
	      f[i]+=g[i];
	      if(f[i]>=10)
	        {
			 f[i]-=10;
			 f[i+1]++;
			}
		 }
	   for(;i<=f[0];i++)
	     if(f[i]>=10)
	       {
		    f[i]-=10;
		    f[i+1]++;
		   }
	   if(f[f[0]+1])
	     f[0]++;
	   if(f[0]==h[0])
	     {
		  for(i=1;i<=f[0];i++)
		    if(f[i]!=h[i])
		      break;
		  if(i>f[0])
		    {
			 for(i=1;i<=l;i++)
			   cout<<s[i-1];
			 cout<<"+";
			 for(;i<r;i++)
			   cout<<s[i-1];
			 cout<<"=";
			 for(;i<=n;i++)
			   cout<<s[i-1];
			 exit(0);
			}
		 }
	  }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	srand(time(0));
	ran();
	do
	  {
	   do
	     q=ran();
	   while(q<1e8);
	   for(i=2;i*i<=q;i++)
	     if(q%i==0)
	       break;
	  }
	while(i*i<=q);
	scanf("%s",&s);
	n=strlen(s);
	a[0]=1;
	x[0]=0;
	for(i=1;i<=n;i++)
	  {
	   a[i]=a[i-1]*10ll%q;
	   x[i]=(x[i-1]*10ll+s[i-1]-'0')%q;
	  }
	for(i=(n+1)/2+1;i/2<=n-i+1;i++)
	  {
	   check(n-i+1,i);
	   check(n-i,i);
	   check(i-(n-i+1)-1,i);
	   check(i-(n-i+1),i);
	  }
	return 0;
}