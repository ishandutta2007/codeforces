#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int a,b;x--;)
	{
		cin>>a>>b;
		cout<<(24-a)*60-b<<endl;
	}
	return 0;
}