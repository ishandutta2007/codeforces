#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,a[3];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a[0]>>a[1]>>a[2];sort(a,a+3);cout<<a[1]+a[2]-a[0]<<endl;
	}
	return 0;
}