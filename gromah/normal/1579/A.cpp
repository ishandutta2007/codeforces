#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int Case;
string str;

int main()
{
	for (cin >> Case; Case; Case --)
	{
		cin >> str;
		int C[3] = {0, 0, 0};
		for (char ch : str)
			C[ch - 'A'] ++;
		puts(C[0] + C[2] == C[1] ? "YES" : "NO");
	}
	return 0;
}