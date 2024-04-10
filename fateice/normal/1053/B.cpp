#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,a[300010],s[300010],x[2];
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	L k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%lld",&k);
	   for(j=0;j<=60;j++)
	     if(k&(1ll<<j))
	       a[i]++;
	   s[i]=s[i-1]+a[i];
	  }
	x[0]=1;
	for(i=1;i<=n;i++)
	  {
	   p+=x[s[i]&1];
	   x[s[i]&1]++;
	   for(j=i,k=0;j>0 && i-j<=80;j--)
	     {
		  k=max(k,(L)a[j]);
		  if(!(s[i]-s[j-1]&1) && k*2>s[i]-s[j-1])
		    p--;
		 }
	  }
	cout<<p<<"\n";
	return 0;
}