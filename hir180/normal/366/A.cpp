#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int main()
{
	cin >> n;
	for(int i=0;i<4;i++)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(min(a,b)+min(c,d)<=n)
		{
			cout << i+1 << " " << min(a,b) << " " << n-min(a,b) << endl;
			return 0;
		}
	}
	puts("-1");
}