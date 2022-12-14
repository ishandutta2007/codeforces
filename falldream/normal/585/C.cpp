#include<iostream>
#include<cstdio>
using namespace std;
inline long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long a,b;

void Solve(long long a,long long b)
{
	if(a==1&&b==1) return;
	else if(a==1) {printf("%lldB",b-1);return;}
	else if(b==1) {printf("%lldA",a-1);return;}
	else if(a<b) printf("%lldB",b/a),Solve(a,b%a);
	else if(a>b) printf("%lldA",a/b),Solve(a%b,b); 
}

int main()
{
	cin>>a>>b;if(gcd(a,b)!=1) return 0*puts("Impossible");
	Solve(a,b); 
	return 0;
}