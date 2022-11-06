#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,a,z,t,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(t==n)
		z=i;
		if(t==1)
		a=i;
	}
	a=min(a,n-a+1);
	z=min(z,n-z+1);
	q=min(a,z);
	cout<<n-q<<endl;
	return 0;
}