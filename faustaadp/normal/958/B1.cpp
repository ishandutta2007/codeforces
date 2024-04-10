#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,d[101010],has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=(n-1)*2;i++)
	{
		cin>>ta;
		d[ta]++;
	}
	for(i=1;i<=n;i++)
		if(d[i]==1)
			has++;
	cout<<has<<"\n";
}