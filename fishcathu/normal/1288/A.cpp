#include<iostream>
#include<cmath>
using namespace std;//63243 999950885
int f(int a,int x)
{
	double n=x*1.0/(a+1);
	int m=n;
	if(m<n)m++;
	return m+a;
}
int main()
{
	int x;
	cin>>x;
	for(int m,n;x--;)
	{
		cin>>m>>n;
		int a=sqrt(n),b=a-1;
		int ans=min(f(a,n),f(b,n));
		cout<<(ans>m?"NO\n":"YES\n");
	}
	return 0;
}