#include<bits/stdc++.h>
using namespace std;
long long n,i,j,hs,o,bu,k,a[300000],b[300000],c[300000];
string s;
int main()
{
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>b[i];
		hs=hs+b[i];
	}
	for(i=0;i<n;i++)
	{
		c[i]=a[i]-b[i];
	}
	sort(c,c+n);
	for(i=0;i<n;i++)
	{
		if(c[i]<=0||i<k)
		{
			hs=hs+c[i];
		}
	}
	cout<<hs<<endl;
}