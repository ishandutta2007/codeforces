#include<bits/stdc++.h>
using namespace std;
long long n,a,c[101010],j,i,hs,ma;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		//scanf("%I64d",&a);
		c[a]++;
	}
	ma=1;
	for(i=2;i<=100000;i++)
	{
		hs=0;
		//if(c[i]>=1)
		//{
			for(j=0;j<=100000;j=j+i)
			{
			//	if(c[j]>=1)
			//	{
			//		cout<<j<<endl;
					hs=hs+c[j];
				//	c[j]=c[j]=0;
			//	}
			}
		//}
		ma=max(hs,ma);
	}
	cout<<ma<<endl;
}