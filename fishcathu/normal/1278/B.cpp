#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int a,b;x--;)
	{
		cin>>a>>b;
		int m=fabs(a-b);
		int n=sqrt(m*2);
		if(n*(n+1)/2<m)n++;
		for(;m%2!=(n+1)/2%2;n++);
		cout<<n<<endl;
	}
	return 0;
}