#include <iostream>
#include <cmath>
using namespace std; 
inline bool prime(int x)
{
	int n = sqrt(x); 
	for (int i = 2; i <= n; i++)
		if (!(x % i))
			return false; 
	return true; 
}
int main()
{
	int n = 0; 
	cin >> n; 
	for (int i = 4; i < n; i++)
	{
		if (prime(i))
		{
			continue; 
		}
		if (!prime(n - i))
		{
			cout << i << " " << n - i << endl; 
			break; 
		}
	}
	return 0; 
}