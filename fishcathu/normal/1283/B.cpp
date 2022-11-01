#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int a,b;x--;)
	{
		cin>>a>>b;
		int m=a/b,n=b/2;
		cout<<min(a,n*(m+1)+(b-n)*m)<<endl;
	}
	return 0;
}