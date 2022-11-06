#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,ta,hz,b[1010101];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		hz+=ta;
	}
	for(i=1;i<=n;i++)
		cin>>b[i];
	sort(b+1,b+1+n);
	if(b[n]+b[n-1]>=hz)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}