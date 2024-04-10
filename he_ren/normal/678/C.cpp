#include<cstdio>
#include<iostream>
typedef long long ll;
using namespace std;

ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}
ll lcm(ll a,ll b){ return a*b/gcd(a,b);}

int main(void)
{
	ll n,a,b,p,q;
	cin>>n>>a>>b>>p>>q;
	cout<< n/a*p + n/b*q - n/lcm(a,b)*min(p,q);
	return 0;
}