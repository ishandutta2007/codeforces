#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

string res[7] = {"0/1", "1/6", "1/3", "1/2", "2/3", "5/6", "1/1"};

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	int a, b;	
	cin >> a >> b;
	cout << res[7 - max(a, b)];
	return 0;
}