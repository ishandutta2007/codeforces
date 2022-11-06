#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll q,L,R,d;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>q;
	while(q--)
	{
		cin>>L>>R>>d;
		ll x=d;
		if(x<L)cout<<x<<"\n";
		else 
		{
			x=R/d;
			x++;
			x*=d;
			cout<<x<<"\n";
		}
	}
}