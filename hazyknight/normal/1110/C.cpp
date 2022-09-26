#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

int q,a;
int ans[26] = {0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int main()
{
	cin >> q;
	while (q--)
	{
		cin >> a;
		int to = 0,i;
		for (i = 0;(1 << i) <= a;i++)
			if (~a & (1 << i))
				to ^= (1 << i);
		if (to == 0)
			cout << ans[i - 1] << endl;
		else
			cout << (to | a) << endl;
	}
	return 0;
}