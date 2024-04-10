#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i;
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n>36)
	{
		cout<<-1<<"\n";
		return 0;
	}
	else
	{
		for(i=1;i<=n/2;i++)
			cout<<8;
		for(i=1;i<=n%2;i++)
			cout<<9;
	}
}