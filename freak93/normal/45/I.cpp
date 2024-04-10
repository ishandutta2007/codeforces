#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

int n,i,a[500],neg;

int mod(int a)
{
	if(a<0)
		return -a;
	return a;
}

bool fcomp(int a,int b)
{
	return mod(a)>mod(b);
}

int main()
{
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1,fcomp);
    for(i=1;i<=n;++i)
		if(a[i]<0)
			++neg;
	if(n==1)
	{
		cout<<a[1];
		return 0;
	}

	for(i=n;i;--i)
		if(a[i]!=0)
			break;
	if(i<=1)
	{
		if(neg%2)
			cout<<"0";
		else
			cout<<a[1];
		return 0;
	}
	for(;i;--i)
		if(a[i]<0&&neg%2)
			break;
		else
			cout<<a[i]<<" ";
	--i;
	for(;i>0;--i)
		cout<<a[i]<<" ";
}