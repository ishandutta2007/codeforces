#include<bits/stdc++.h>
//#define ll long long
using namespace std;
long long a[10],x,y,i;
int main()
{

	for(i=1;i<=4;i++)
		cin>>a[i];
	cin>>x>>y;
	if((abs(a[3]-a[1])%x==0)&&(abs(a[4]-a[2])%y==0)&&(abs((a[3]-a[1])/x)%2==abs((a[4]-a[2])/y)%2))	cout<<"YES\n";
	else	cout<<"NO\n";
}