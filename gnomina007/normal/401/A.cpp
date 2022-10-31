#include <iostream>
#include <cmath>
using namespace std;
long long a, b, c[100], i, n, x, sum, ans;
int main()
{
	cin>>n>>x;
	for(i=0; i<n; i++)
	{
		cin>>a;
		sum=sum+a;
	}
	sum=abs(sum);
	ans=(sum+x-1)/x;
	cout<<ans;

}