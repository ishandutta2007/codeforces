#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;
	cout << s;
	reverse(s.begin(),s.end());
	cout << s << endl;
	return 0;
}