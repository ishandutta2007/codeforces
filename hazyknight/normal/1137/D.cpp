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
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

int k;

string s;

int main()
{
	do
	{
		cout << "next 0" << endl;
		cout.flush();
		cin >> k;
		for (int i = 0;i < k;i++)
			cin >> s;
		cout << "next 0 1" << endl;
		cout.flush();
		cin >> k;
		for (int i = 0;i < k;i++)
			cin >> s;
	}while (k > 2);
	do
	{
		cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
		cout.flush();
		cin >> k;
		for (int i = 0;i < k;i++)
			cin >> s;
	}while (k > 1);
	cout << "done" << endl;
	return 0;
}