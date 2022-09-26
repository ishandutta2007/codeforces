#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int a,b,N;
int v[1000005];

vector<int> A,B;

int main()
{
	cin >> a >> b;
	int sum = a + b;
	for (int i = 1;;i++)
	{
		if ((long long)i * (i + 1) > (long long)sum * 2)
		{
			for (int j = 1;j < i;j++)
				v[j] = j;
			N = i - 1;
			break;
		}
	}
	for (int i = N;i >= 1;i--)
		if (a >= v[i])
		{
			A.push_back(v[i]);
			a -= v[i];
		}
		else
			B.push_back(v[i]);
	cout << A.size() << endl;
	for (int i = 0;i < A.size();i++)
		cout << A[i] << ' ';
	cout << endl;
	cout << B.size() << endl;
	for (int i = 0;i < B.size();i++)
		cout << B[i] << ' ';
	cout << endl;
	return 0;
}