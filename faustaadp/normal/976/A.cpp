#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,sat,nol;
char ct;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ct;
		if(ct=='1')
			sat++;
		else
			nol++;
	}
	if(n==1&&nol==1)
	{
		cout<<0<<"\n";
		return 0;
	}
	cout<<1;
	for(i=1;i<=nol;i++)	cout<<0;
	cout<<"\n";
}