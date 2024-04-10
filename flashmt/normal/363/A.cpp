#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

string digit[10];

int main()
{
	for (int i = 0; i < 10; i++)
	{
		if (i < 5) digit[i] += "O-|";
		else digit[i] += "-O|";
		for (int j = 0; j < 5; j++) digit[i] += (j == i % 5 ? '-' : 'O');
	}
	
	int n;
	cin >> n;
	if (!n) cout << digit[0] << endl;
	else
		while (n) cout << digit[n % 10] << endl, n /= 10;
}