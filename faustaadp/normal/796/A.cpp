#include<bits/stdc++.h>
using namespace std;
long long n,m,r,i,a[122122],hs;
int main()
{
	cin>>n>>m>>r;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	hs=99999999999999999;
	for(i=m-1;i>=1;i--)
	{
		if(a[i]<=r&&a[i]!=0)
		{
		//	cout<<i<<endl;
			hs=min(hs,abs(m-i));
		}
	}
	//cout<<hs<<endl;
	for(i=m+1;i<=n;i++)
	{
		if(a[i]<=r&&a[i]!=0)
		{
			hs=min(hs,abs(m-i));
		}
	}
	cout<<hs*10<<endl;
}