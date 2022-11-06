#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,hs,i;
double hz,hn,ht;
int main()
{
	cin>>n>>a;
	hz=(n-2)*180;
	hz=hz/n;
	hn=hz/(n-2);
	ht=1000000000000000000;
	for(i=3;i<=n;i++)
	{
		if(abs(hz-a)<ht)
		{
			ht=abs(hz-a);
			hs=i;
		}
	//	cout<<hz<<endl;
		hz=hz-hn;
	}
	cout<<"1 2 "<<hs<<endl;
}