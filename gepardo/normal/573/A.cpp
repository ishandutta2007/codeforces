#include <iostream>

using namespace std;

int main()
{
	int n, a, p = -1, yes = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		while (a % 2 == 0) a /= 2;
		while (a % 3 == 0) a /= 3;
		if (p < 0) p = a;
		if (a != p) yes = false;
	}
	cout << (yes ? "Yes" : "No");
}