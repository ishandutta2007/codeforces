#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
#include <complex>

using namespace std;

string s;

string ask(int x,int y)
{
	cout << "? " << x << ' ' << y << endl;
	cout.flush();
	cin >> s;
	return s;
}

int main()
{
	while (cin >> s && s == "start")
	{
		bool ok = false;
		for (int i = 1;i <= 1000000000;i <<= 1)
			if (ask(i * 2,i) == "y")
			{
				int low = i,high = i * 2;
				while (low < high)
				{
					int mid = (low + high) >> 1;
					if (ask(low - 1,mid) == "y")
						low = mid + 1;
					else
						high = mid;
				}
				ok = true;
				cout << "! " << low << endl;
				cout.flush();
				break;
			}
		if (!ok)
		{
			cout << "! " << 1 << endl;
			cout.flush();
		}
	}
	return 0;
}