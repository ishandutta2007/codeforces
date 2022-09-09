#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

int main(void)
{
	ll n,m;
	int a,b;
	cin>>n>>m>>a>>b;
	cout<<min( (m-n%m) * a, n%m * b);
	return 0;
}