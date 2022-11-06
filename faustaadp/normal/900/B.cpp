#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,i,hz;
int main()
{
	cin>>a>>b>>c;
	a=a*10;
	for(i=1;i<=1000000;i++)
	{
		hz=a/b;
		a=a%b;
		a=a*10;
//		cout<<hz<<"\n";
		if(hz==c)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<-1<<"\n";
}