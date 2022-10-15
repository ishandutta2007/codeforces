#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int n, m; cin >> n >> m;
	int g = __gcd(n, m);	                

	for (int i = 1; i <= 5000; i++)
		for (int j = 1; j <= 5000; j++)
		{
			if (i * i + j * j == g * g)
			{
				
				if (j * m / g != i * n / g)
				{ 
					cout << "YES" << endl;
					cout << "0 0" << endl;
					cout << j * m / g << " " << i * m / g << endl;
					cout << i * n / g << " " << -j * n / g << endl;
					return 0;
				}
				if (i * m / g != j * n / g)
				{ 
					cout << "YES" << endl;
					cout << "0 0" << endl;
					cout << j * m / g << " " << i * m / g << endl;
					cout << -i * n / g << " " << j * n / g << endl;
					return 0;
				}

				
			}
		} 

	cout << "NO";
}