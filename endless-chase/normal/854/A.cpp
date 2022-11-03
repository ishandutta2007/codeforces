#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int gcd(int a,int b)
{
	return (!b)?a:gcd(b,a%b);
}
int main()
{
	int x,j;
	cin>>x;
	for(int i=x/2;i>0;i--)
	{
		j=x-i;
		if(gcd(i,j)==1)
		{ 
		
		cout<<i<<' '<<j;
		break;
		} 
	
	}
	return 0;
}