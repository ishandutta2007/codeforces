#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	double ans=0;
	for(x++;--x;)
	{
		ans+=1.0/x;
	}
	cout<<ans;
	return 0;
}