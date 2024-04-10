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

char s[1000100];

int main()
{
	scanf("%s", s);
	int n = strlen(s), female = 0, maxTime = 0, continuousFemale = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'F') 
		{
			int timeNeeded = i - female++;
			if (timeNeeded) timeNeeded += continuousFemale++;
			maxTime = max(maxTime, timeNeeded);
		}
		else continuousFemale = max(0, continuousFemale - 1);
	cout << maxTime << endl;
}