#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,hs;
char a[10101010];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
	{
		if(a[i]=='S'&&a[i+1]=='F')
			hs++;
		else
		if(a[i]=='F'&&a[i+1]=='S')
			hs--;
	}
	if(hs>0)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}