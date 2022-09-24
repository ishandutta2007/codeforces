#include <iostream>
#include <cmath>
using namespace std;
char a[1005][1005];
int main()
{
	int n,s=0;
	cin>>n;
	while(n)s+=n%2,n/=2;
	cout<<s;
}