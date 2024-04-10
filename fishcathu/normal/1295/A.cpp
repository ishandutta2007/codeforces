#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int n;x--;)
	{
		cin>>n;
		if(n%2)
		{
			cout<<7;
			n-=3;
		}
	    for(;n;n-=2)cout<<1;
		cout<<endl;
	}
	return 0;
}