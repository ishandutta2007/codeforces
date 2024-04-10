#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int n,p,k;

int main()
{
	cin >> n >> p >> k;
	int st = max(1,p - k),ed = min(n,p + k);
	if (st != 1)
		cout << "<< ";
	for (int i = st;i <= ed;i++)
	{
		if (i == p)
			cout << '(' << i << ") ";
		else
			cout << i << ' ';
	}
	if (ed != n)
		cout << ">>" << endl;
	return 0;
}