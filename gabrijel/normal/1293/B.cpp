#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

double rj = 0;

int main()
{
	int n;
	cin >> n;
	REP(i, 0, n)
	{
		rj += (double) 1 / (n - i);
	}
	cout << rj << endl;
	return 0;
}