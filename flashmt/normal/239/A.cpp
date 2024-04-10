#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int y,k,n,ok=0;
	cin >> y >> k >> n;
	for (int i=1;i*k<=n;i++)
		if (i*k>y) cout << i*k-y << ' ', ok=1;
	if (!ok) cout << -1;
}