#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,l,r,i;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>l>>r;
	ll h2=1;
	ll h1=1;
	ll h3=1;
	for(i=1;i<r;i++)
		h3*=2;
	for(i=1;i<=r;i++)
		h2*=2;
	h2--;
	for(i=1;i<=l;i++)
		h1*=2;
	h1--;
	//cout<<h1<<" "<<h2<<" "<<h3<<"\n";
	h1+=(n-l);
	h2+=(n-r)*h3;
	cout<<h1<<" "<<h2<<"\n";
}