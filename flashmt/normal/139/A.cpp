#include <iostream>
using namespace std;

int main()
{
	int n,a[7],x=6;
	cin >> n;
	for (int i=0;i<7;i++) cin >> a[i];
	do
	{
		x=(x+1)%7;
		n-=a[x];
	} while (n>0);
	cout << x+1 << endl;
}