#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n,k,A,B,cntA,cntB;

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= k + 1;i++)
	{
		cout << "? ";
		for (int j = 1;j <= k + 1;j++)
			if (i != j)
				cout << j << ' ';
		cout << endl;
		cout.flush();
		int a,b;
		cin >> a >> b;
		if (!A)
		{
			A = b;
			cntA++;
		}
		else if (b == A)
			cntA++;
		else if (!B)
		{
			B = b;
			cntB++;
		}
		else
			cntB++;
	}
	if (A > B)
	{
		swap(cntA,cntB);
		swap(A,B);
	}
	cout << "! " << cntB << endl;
	return 0;
}