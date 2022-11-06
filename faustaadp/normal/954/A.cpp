#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,has;
char a[101010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	has=n;
	for(i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			has--;
			i++;
		}
	}
	cout<<has<<"\n";
}