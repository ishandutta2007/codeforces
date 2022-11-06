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
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n<=5)
		cout<<-1<<"\n";
	else
	{
		cout<<"1 2\n";
		cout<<"1 3\n";
		cout<<"1 4\n";
		cout<<"2 5\n";
		cout<<"2 6\n";
		for(i=7;i<=n;i++)
			cout<<"2 "<<i<<"\n";
	}
	for(i=1;i<n;i++)
		cout<<i<<" "<<i+1<<"\n";
}