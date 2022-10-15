#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n; cin >> n;
	int c = 0;
	for (int i = 0; i < 1000; i++)
	{
		int q = i, w = 0, p = 1;
		while (q)
		{
			w += (q % 2) * p;			
			q /= 2;        
			p *= 10;                               
		}
		//cout << i << " " << w << endl;
		if (w <= n) c++;
	}
	c--;
	cout << c;
}