#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

int n;

string s;

int dis(char s1,char s2)
{
	int t = abs(s1 - s2);
	return min(t,26 - t);
}

int main()
{
	cin >> n >> s;
	int ans = 1000000;
	for (int i = 0;i + 3 < n;i++)
		ans = min(ans,dis(s[i],'A') + dis(s[i + 1],'C') + dis(s[i + 2],'T') + dis(s[i + 3],'G'));
	cout << ans << endl;
	return 0;
}