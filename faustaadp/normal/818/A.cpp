#include<bits/stdc++.h>
#define ll long long
ll n,k,r;
using namespace std;
int main()
{
	cin>>n>>k;
	r=n/2/(k+1);
	cout<<r<<" "<<r*k<<" "<<n-(r+r*k)<<endl;
}