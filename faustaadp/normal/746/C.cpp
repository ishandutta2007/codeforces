#include<bits/stdc++.h>
using namespace std;
long long n,a,b,j,t,p,d,has,his,hos;
int main()
{
	cin>>n>>a>>b;
	cin>>t>>j;
	cin>>p>>d;
	has=j*abs(a-b);
	if(d==1&&a<b)
	{
		if(p<=a)
		{
			his=t*(b-p);
		}
		else
		{
			his=t*((b-p)+(n*2));
		}
	}
	else
	if(d==-1&&b<a)
	{
		if(p>=a)
		{
			his=t*(p-b);
		}
		else
		{
			his=t*((p-b)+(n*2));
		}
	}
	else
	{
		if(a<b)
		{
			his=t*((p*2)+(b-p));
		}
		else
		{
			his=t*(((n-p)*2)+(p-b));
		}
	}
//	cout<<his<<" "<<has<<endl;
	cout<<min(his,has)<<endl;
}