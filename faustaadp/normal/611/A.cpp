#include<bits/stdc++.h>
using namespace std;
int n,a[8]={0,52,52,52,52,53,53,52};
string s;
int main()
{
	cin>>n>>s>>s;
	if(s=="week")
	{
		cout<<a[n]<<endl;
	}
	else
	{
		if(n==31)
			cout<<7<<endl;
		else
		if(n==30)
			cout<<11<<endl;
		else
			cout<<12<<endl;
	}
}