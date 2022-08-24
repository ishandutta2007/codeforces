#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,q,x[100010],a[1000],p;
inline int power(int a,int b,int q)
{
	//cout<<a<<" "<<b<<" "<<q<<"\n";
	if(!b)
	  return 1;
	int c=power(a,b>>1,q);
	c=min((L)c*c%q+q,(L)c*c);
	if(b&1)
	  c=min((L)c*a%q+q,(L)c*a);
	return c;
}
inline int solve(int i,int j,int k)
{
	if(i>j)
	  return 1;
	if(k==p)
	  return min(x[i],2);
	return power(x[i],solve(i+1,j,k+1),a[k]);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	scanf("%d",&m);
	a[1]=q;
	for(p=2;a[p-1]>1;p++)
	  {
	   for(k=a[p-1],i=2,j=1;i*i<=k;i++)
	     if(k%i==0)
	       {
			j*=i-1;
			k/=i;
			while(k%i==0)
			  {
			   j*=i;
			   k/=i;
			  }
		   }
	   if(k>1)
	     j*=k-1;
	   a[p]=j;
	  // cout<<a[p]<<"\n";
	  }
	p--;
	while(m--)
	  {
	   scanf("%d%d",&i,&j);
	   printf("%d\n",solve(i,j,1)%q);
	  }
	return 0;
}