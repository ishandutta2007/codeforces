#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,xa,ya,xb,yb,xc,yc;

int main()
{
	cin >> n >> xa >> ya >> xb >> yb >> xc >> yc;
	if ((xa - xb) * (xa - xc) > 0 && (ya - yb) * (ya - yc) > 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}