#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

int main(void)
{
	ll a,b;
	cin>>a>>b;
	while(a && b)
	{
		if(a >= (b<<1ll)) a %= b<<1ll;
		else if(b >= (a<<1ll)) b %= a<<1ll;
		else break;
	}
	cout<<a<<' '<<b;
	return 0;
}