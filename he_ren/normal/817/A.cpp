#include<cstdio>
#include<cmath>
#include<iostream>
typedef long long ll;
using namespace std;

int main(void)
{
	ll a,b,c,d,x,y;
	cin>>a>>b>>c>>d>>x>>y;
	ll e=abs(c-a), f=abs(d-b);
	if(e%x==0 && f%y==0 && (e/x)%2==(f/y)%2) printf("YES");
	else printf("NO");
	return 0;
}