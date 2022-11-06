#include<bits/stdc++.h>
using namespace std;
long long nn,n,i,a[120201],m,x,hs,sh,shs,j;
int main()
{
	shs=-999920390390239;
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		//sh=sh+a[i];
	}
	x=1;
//	cout<<"j";
//	nn=sqrt(nn);
	while(x<=(n/3))
	{
	//	cout<<x<<" ";
		if(n%x==0)
		{
	//		cout<<x<<endl;
			for(i=0;i<x;i++)
			{
				hs=0;
				for(j=i;j<n;j=j+x)
				{
				 	hs=hs+a[j];
//				 	cout<<j<<" ";
				}
				shs=max(hs,shs);
//				cout<<shs<<" ";	
			}
		}
		x++;
	}
	cout<<shs<<endl;
}