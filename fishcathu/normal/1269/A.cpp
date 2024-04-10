#include<iostream>
using namespace std;
bool f(int a)
{
	int i=2;
	for(;i*i<=a&&a%i;i++);
	return i*i>a;
}
int main()
{
	int x;
	cin>>x;
	int i=4;
	for(;f(i+x);i+=2);
	cout<<i+x<<' '<<i;
	return 0;
}