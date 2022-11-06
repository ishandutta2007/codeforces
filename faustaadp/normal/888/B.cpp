#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,a[1010101],hs,x,y;
char tc;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>tc;
		if(tc=='D')
			x--;
		else
		if(tc=='U')
			x++;
		else
		if(tc=='R')
			y++;
		else
			y--;
	}
	cout<<n-(abs(x)+abs(y))<<"\n";
}