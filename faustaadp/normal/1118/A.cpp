#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,a,b,h1,h2;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		h1=a*n;
		if(n%2==1)
			h2=n/2*b+a;
		else
			h2=n/2*b;
		cout<<min(h1,h2)<<"\n";
	}
}