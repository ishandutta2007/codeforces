#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a[3][3] = {0}, x;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> x;
			if (x & 1 ^ 1) continue;
			for (int ii = 0; ii < 3; ii++)
				for (int jj = 0; jj < 3; jj++)
					if (abs(i - ii) + abs(j - jj) <= 1)
						a[ii][jj] ^= 1;
		}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) cout << (a[i][j] ^ 1);
		cout << endl;
	}
}