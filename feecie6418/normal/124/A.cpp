#include <iostream>
#include <cmath>
using namespace std;
char a[1005][1005];
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	cout<<min(n-a,b+1);
}