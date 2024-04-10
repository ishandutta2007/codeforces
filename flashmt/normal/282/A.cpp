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

int main()
{
	int n, x = 0;
	string s;
	cin >> n;
	while (n--) 
	{
		cin >> s;
		if (s[1] == '+') x++;
		else x--;
	}
	cout << x << endl;
}