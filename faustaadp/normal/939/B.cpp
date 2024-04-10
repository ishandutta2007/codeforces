#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll mi,n,k,i,ta,h1,h2;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	mi=LLONG_MAX;
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		cin>>ta;
		if(n%ta<mi)
		{
			mi=n%ta;
			h1=i;
			h2=n/ta;
		}
	}
	cout<<h1<<" "<<h2<<"\n";
}