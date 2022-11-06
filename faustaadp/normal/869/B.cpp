#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a,b,i,hs,hz;
int main()
{
	cin>>a>>b;
	if(b-a>15)
		cout<<0<<"\n";
	else
	{
		hs=1;
		for(i=a+1;i<=b;i++)
		{
			hz=i%10;
			hs=hs*hz;
			hs=hs%10;
		}
		cout<<hs<<"\n";
	}
}