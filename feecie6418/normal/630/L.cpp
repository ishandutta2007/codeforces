#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,ans=1;
int main()
{
	cin>>n;
	n=n/10000*10000+n/100%10*1000+n%10*100+n/10%10*10+n/1000%10;
	for(int i=1;i<=5;i++)ans=ans*n%100000;
	printf("%05lld\n",ans);
    return 0;
}