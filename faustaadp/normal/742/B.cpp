#include<bits/stdc++.h>
using namespace std;
long long n,k,i,j,a[100100],b[10010000],p;
unsigned long long tt;
int main()
{
	tt=0;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
//	for(i=1;i<n;i++)
//		cout<<a[i];
	for(i=0;i<n;i++)
	{
	//	cout<<a[i]<<" "<<k<<endl;
		p=a[i]^k;
		//cout<<p;
		if(p==a[i])
		{
				tt=tt+b[p]-1;
		}
		else
		{
			//if(b[a[i]]>0)
			//cout<<b[a[i]]<<"i "<<i<<"t"<<p<<endl;
			tt=tt+b[p];
		}
		//cout<<p<<endl;
	}
	tt=tt/2;
	cout<<tt<<endl;
	return 0;
}