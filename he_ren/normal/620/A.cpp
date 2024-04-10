#include<cstdio>
#include<iostream>
typedef long long ll;
using namespace std;

inline ll abs_ll(ll x){ return x<0? -x: x;}

int main(void)
{
	ll x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	ll dx=abs_ll(x1-x2), dy=abs_ll(y1-y2);
	cout<<max(dx,dy);
	return 0;
}