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
	string s;
	cin >> s;
	int n = 1;
	for (int i = 2; i < int(s.size()); i++)
	{
		if (s[i] == s[n] && s[i] == s[n - 1]) continue;
		if (s[i] == s[n] && n >= 2 && s[n - 1] == s[n - 2]) continue;
		s[++n] = s[i];
	}
	cout << s.substr(0, n + 1) << endl;
}