#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;

int n,k,m,t;

int main()
{
	cin >> n >> k >> m >> t;
	for (int tp,l,i = 1;i <= t;i++)
	{
		cin >> tp >> l;
		if (tp)
		{
			if (l <= k)
				k++;
			n++;
		}
		else
		{
			if (k <= l)
				n = l;
			else
			{
				k -= l;
				n -= l;
			}
		}
		cout << n << ' ' << k << endl;
	}
	return 0;
}