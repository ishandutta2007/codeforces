#include<cstdio>
#include<iostream>
typedef long long ll;
using namespace std;

int main(void)
{
	ll n,k;
	cin>>n>>k;
	ll x=(n/2)/(k+1), y=k*x, z=n-x-y;
	cout<<x<<' '<<y<<' '<<z;
	return 0;
}