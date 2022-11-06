#include<bits/stdc++.h>
using namespace std;
long long x,y,hs,i;
int main()
{
	cin>>x>>y;
	for(i=1;i<=1000000000;i++)
	{
		x=x*3;
		y=y*2;
		if(x>y)
			break;
	}
	cout<<i<<endl;
}