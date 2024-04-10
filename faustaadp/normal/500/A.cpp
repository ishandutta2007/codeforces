#include<bits/stdc++.h>
using namespace std;
int n,t,i,x,a[100100];
bool b;
int main()
{
	cin>>n>>t;
	x=1;
	b=0;
	for(i=1;i<=n-1;i++)
	{
		cin>>a[i];
	}
	while(x<t)
	{
		x=x+a[x];
		//cout<<x<<endl;
		if(x==t)
		{
			b=1;
			break;	
		}	
	}
	if(t==1)
		b=1;
	if(b==1)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}