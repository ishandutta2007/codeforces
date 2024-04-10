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
	int d[26] = {0}, odd = 0;
	string s;
	cin >> s;
	for (int i = 0; i < int(s.size()); i++) d[s[i] - 'a'] ^= 1;
	for (int i = 0; i < 26; i++) odd += d[i];
	if (odd > 1 && odd % 2 == 0) puts("Second");
	else puts("First");
}