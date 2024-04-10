#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;

string s;

int main()
{
	cin >> s;
	for (int i = 0;i < (int)s.size() - 2;i++)
	{
		char a = s[i],b = s[i + 1],c = s[i + 2];
		if (a > b)
			swap(a,b);
		if (a > c)
			swap(a,c);
		if (b > c)
			swap(b,c);
		if (a == 'A' && b == 'B' && c == 'C')
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}