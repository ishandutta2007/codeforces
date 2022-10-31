#include <iostream>
using namespace std;
long long n, d, t[500], i, sum;
int main()
{
	cin>>n>>d;
	sum=10*(n-1);
	for(i=1; i<=n; i++)
	{
		cin>>t[i];
		sum=sum+t[i];
	}
	if(sum>d)
	{
		cout<<-1;
	}
	else
	{
		cout<<2*(n-1)+(d-sum)/5;
	}
}