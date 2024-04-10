#include<cstdio>
#include<iostream>
using namespace std;
long long l,r,cnt;
int main()
{
	cin>>l>>r;
	for (int i=2;i<=63;i++)
	for (int j=0;j<i-1;j++)
	{
		long long now=(1LL<<i)-1-(1LL<<j);
		if (now>=l&&now<=r) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}