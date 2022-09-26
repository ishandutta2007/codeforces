#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <cmath> 

using namespace std;

long long xa,ya,xb,yb,xc,yc;

int main()
{
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	if (xa == xb && xb == xc && ya == yb && yb == yc)
		cout << "Yes" << endl;
	else if ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) != (xb - xc) * (xb - xc) + (yb - yc) * (yb - yc))
		cout << "No" << endl;
	else if ((ya - yb) * (xb - xc) == (yb - yc) * (xa - xb))
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}