#include<bits/stdc++.h>
using namespace std;
int n,tt,i,a[10000];
int main()
{
	cin>>n;
	while(1)
	{
	//	cout<<n<<" ";
		i++;
		if(n-i>=0)
		{
			a[i]=i;
			n=n-i;
		}
		else
		{
			a[i-1]=a[i-1]+n;
			n=0;
			i--;
			break;
		}
	}
//	cout<<a[1]<<a[2]<<" ";
	cout<<i<<endl;
	tt=i;
	for(i=1;i<=tt;i++)
	{
		if(i==tt)
			cout<<a[i]<<endl;
		else
			cout<<a[i]<<" ";
	}
}