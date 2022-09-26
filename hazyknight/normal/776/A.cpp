#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n;

string A,B,C,D;

int main()
{
	cin >> A >> B >> n;
	cout << A << ' ' << B << endl;
	while (n--)
	{
		cin >> C >> D;
		if (A == C)
			A = D;
		else
			B = D;
		cout << A << ' ' << B << endl;
	}
	return 0;
}