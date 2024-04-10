#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cctype>

using namespace std;

int main()
{
	string s;
	cin >> s;
	s[0] = toupper(s[0]);
	cout << s << endl;
	return 0;
}