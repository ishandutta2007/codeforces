#include<bits/stdc++.h>
using namespace std;
unsigned long long k,n,m;
unsigned long long powo(unsigned long long x,unsigned long long y)
{
	long long oo,aa;
	if(y==0)
		return 1;
	else
	if(y==1)
		return x;
	else
	{
		oo=powo(x,y/2);
		if(y%2==0)
		{
			return oo*oo%k;
		}
		else
		{
			oo=oo*oo%k;
			return oo*x%k;
		}
	}
}
int main()
{
	k=1000000007;
	cin>>n;
	n=powo(2,n);
//	cout<<"n"<<n<<endl;
	if(n%2==0)
	{
		m=n/2%k;
		m=m*(n+1)%k;
	}
	else
	{
		m=(n+1)/2%k;
		m=m*n%k;
	}
	cout<<m<<endl;
}