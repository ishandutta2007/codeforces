#include<cstdio>
#include<iostream>
typedef long long ll;
using namespace std;

int main(void)
{
	ll n;
	cin>>n;
	for(ll i=1; i<n; ++i) n-=i;
	cout<<n;
	return 0;
}