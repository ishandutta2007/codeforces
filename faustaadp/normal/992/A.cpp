#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,b[202020],has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(ta==0)
			continue;
		if(!b[ta+100000])
			has++;
		b[ta+100000]=1;
	}
	cout<<has<<"\n";
}