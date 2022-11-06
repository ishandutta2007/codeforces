#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	cin>>n;
	if(n==0)
		cout<<1<<endl;
	else
	{
	n=n%4;
	if(n==1)
		cout<<8<<endl;
	if(n==2)
		cout<<4<<endl;
	if(n==3)
		cout<<2<<endl;
	if(n==0)
		cout<<6<<endl;
	}
}