#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,a[1010101],hs;
bool b[1010101];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=n;i>=1;i--)
	{
		if(!b[a[i]])
		{
			b[a[i]]=1;
			hs=a[i];
		}
	}
	cout<<hs<<"\n";
}