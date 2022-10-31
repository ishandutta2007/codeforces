#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b)
{
	if (a<b) swap(a,b);
	if (b==0) return 0;
	return gcd(b,a%b)+a/b;
}
int main()
{
	LL a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	return 0;
}