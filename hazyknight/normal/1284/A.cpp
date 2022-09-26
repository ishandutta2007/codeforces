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

int n,m,q;

string s[25];
string t[25];

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> s[i % n];
	for (int i = 1;i <= m;i++)
		cin >> t[i % m];
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		cout << s[x % n] + t[x % m] << endl;
	}
	return 0;
}