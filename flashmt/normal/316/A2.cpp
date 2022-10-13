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
	int flag[26] = {0}, difChar = 10, zero = 0;
	string s;
	cin >> s;
	long long ans = 1;
	
	if (s[0] == '?') ans = 9;
	else
		if (s[0] >= 'A' && s[0] <= 'Z')
		{
			flag[s[0] - 'A'] = 1;
			ans = --difChar;
		}
	
	for (int i = 1; i < int(s.size()); i++)	
		if (s[i] == '?') zero++;
		else
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				if (flag[s[i] - 'A']) continue;
				flag[s[i] - 'A'] = 1;
				ans *= difChar--;
			}
			
	cout << ans;
	while (zero--) cout << 0;
}