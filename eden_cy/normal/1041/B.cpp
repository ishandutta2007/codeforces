#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef long long ll;
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
int main() {
	ll a,b,x,y;
	cin>>a>>b>>x>>y;
	ll g=gcd(x,y);
	x/=g;y/=g;
	cout<<min(a/x,b/y)<<endl;
	return 0;
}