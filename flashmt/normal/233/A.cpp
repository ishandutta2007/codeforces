#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n%2) cout << -1 << endl;
	else
		for (int i=1;i<=n;i++)
			cout << i+(i%2?1:-1) << ' ';
}