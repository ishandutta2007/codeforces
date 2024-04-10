#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x;
	cin >> x;
	if (x==3) cout << 5 << endl;
	else
		for (int n=1;;n+=2)
			if ((n*n+1)/2>=x)
			{
				cout << n << endl;
				break;
			}
}