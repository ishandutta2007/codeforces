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
#include <iomanip>

using namespace std;

int q,l,r;

int main()
{
	ios::sync_with_stdio(false);
	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		long long stp = (l & 1) ? l + 1 : l,edp = (r & 1) ? r - 1 : r;
		long long stn = (l & 1) ? l : l + 1,edn = (r & 1) ? r : r - 1;
		cout << (edp + stp) * ((edp - stp) / 2 + 1) / 2 - (stn + edn) * ((edn - stn) / 2 + 1) / 2 << endl;
	}
	return 0;
}