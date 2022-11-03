#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
	long long a,b;
	cin>>a>>b;
	long long unit=1;
	for(long long i=a+1;i<a+6&&i<=b;i++)
	{
		unit*=(i%10);
		unit%=10;
	}
	cout<<unit;
	return 0;
}