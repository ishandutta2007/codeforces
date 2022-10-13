#include <iostream>
using namespace std;

int d[100100],a,b,m,r;

int main()
{
	cin >> a >> b >> m >> r;
	d[r]=1;
	for (int i=2;;i++)
	{
		r=(r*a+b)%m;
		if (d[r]) 
		{
			cout << i-d[r] << endl;
			return 0;
		}
		d[r]=i;
	}
}