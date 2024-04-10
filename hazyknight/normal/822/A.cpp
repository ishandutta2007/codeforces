#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int a,b;

int main()
{
	cin >> a >> b;
	int mul = 1;
	for (int i = 1;i <= min(a,b);i++)
		mul *= i;
	cout << mul << endl;
	return 0;
}