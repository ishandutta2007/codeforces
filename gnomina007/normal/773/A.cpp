#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;
int main()
{
	
	long long t, i, x, y, p, q, x1, y1, kl, x2, y2,ma;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> x >> y >> p >> q;
                 y=y-x;
		if (q == 1)
		{
                    if(p==1)
{
			if (y==0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << -1 << endl;
			}
}
		}
		if (p == 0)
		{
			if (x ==0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		if (p != 0)
		{
			if (q != 1)
			{
				kl = q - p;
				x2 = ((x + p - 1) / p);
				y2 = ((y + kl - 1) / kl);
				ma = max(x2, y2);
				cout << (ma*q -y-x) << endl;
			}
		}
	}


}