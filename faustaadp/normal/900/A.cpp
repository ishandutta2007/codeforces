#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,ta,a[1010101],hz,hs;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(ta<0)
			a[0]++;
		else
			a[1]++;
		cin>>ta;
	}
	if(a[0]<=1||a[1]<=1)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}