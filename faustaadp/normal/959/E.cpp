#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,du[101],i,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	du[0]=1;
	for(i=1;i<=50;i++)
		du[i]=du[i-1]*2;
	//cout<<du[50]<<"\n";
	for(i=0;i<=49;i++)
	{
	//	cout<<i<<" "<<du[i]<<" "<<n+du[i-1]-1<<'\n';
		has+=du[i]*((n+du[i]-1)/du[i+1]);
	}
	cout<<has<<"\n";
}