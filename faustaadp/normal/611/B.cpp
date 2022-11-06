#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,i,j,su,nn,ti,ck;
string s;
int main()
{
	cin>>a>>b;
	su=0;
	for(i=2;i<=64;i++)
	{
		nn=pow(2,i)-1;
		ti=1;
		for(j=1;j<i;j++)
		{
			ck=nn-ti;
			if(ck>=a&&ck<=b)
				su++;
			ti=ti*2;
		}
	}
	cout<<su<<endl;
}