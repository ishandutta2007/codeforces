#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 105;

int n;;

string S;

set<string> s;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> S;
		puts(s.find(S) == s.end() ? "NO" : "YES");
		s.insert(S);
	}
	return 0;
}