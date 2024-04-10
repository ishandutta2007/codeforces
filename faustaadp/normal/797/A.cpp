#include<bits/stdc++.h>
using namespace std;
long long n,k,ti,tt,a[1100000],i,kk;
int main()
{
	cin>>n>>k;
	kk=k;
	ti=1;
	while(k>1&&ti<n)
	{
		ti++;
		while(n%ti==0)
		{
			if(k<=1)
				break;
	//		cout<<ti;
			tt++;
			a[tt]=ti;
			n=n/ti;
			k--;
		}
	}
	//cout<<k<<endl;
	if(k>1||n==1)
		cout<<-1<<endl;
	else
	{
		for(i=1;i<kk;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<n<<endl;
	}
}