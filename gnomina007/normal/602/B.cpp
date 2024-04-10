
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
long long  st(long long a, long long b)
{
	int x;
	if(b==0)
	{
		return 1;
	}
	else
	{
		x=st(a, b-1);
		x=(x*a);
		return x;
	}
}
long long n, m, i, a[100005], lb, rb, a1, a2, a3, x1, x2, b[100005], c[100005], k, d[100005], ans, sum;
int main()
{
	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	b[0]=0;
	k=0;
	for(i=1; i<n; i++)
	{
		if(a[i]!=a[i-1])
		{
			k++;
			b[k]=i;
			d[k-1]=(a[i]-a[i-1])*(2*(k%2)-1);
		}
	}
	for(i=0; i<k; i++)
	{
		c[i]=b[i+1]-b[i];
	}
	c[k]=n-b[k];
	for(i=0; i<3; i++)
	{
		//cout<<d[i]<<' ';
	}
	if(k<=1)
	{
		cout<<n;
	}
	else
	{
	   sum=c[0]+c[1];
	   for(i=1; i<k; i++)
	   {
		   if(d[i]==d[i-1])
		   {
			   sum=sum+c[i+1];
		   }
		   else
		   {
			   ans=max(ans, sum);
			   sum=c[i]+c[i+1];
		   }
	   }
	   ans=max(ans, sum);
	   cout<<ans;
	}
	


}