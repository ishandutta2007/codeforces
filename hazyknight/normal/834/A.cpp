#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

char c1,c2;

int n;

map<char,char> m1,m2;

int main()
{
	m1['v'] = '<';
	m1['<'] = '^';
	m1['^'] = '>';
	m1['>'] = 'v';
	m2['v'] = '>';
	m2['<'] = 'v';
	m2['^'] = '<';
	m2['>'] = '^';
	cin >> c1 >> c2 >> n;
	n %= 4;
	bool ok1 = false,ok2 = false;
	char tmp = c1;
	for (int i = 1;i <= n;i++)
		tmp = m1[tmp];
	if (tmp == c2)
		ok1 = true;
	tmp = c1;
	for (int i = 1;i <= n;i++)
		tmp = m2[tmp];
	if (tmp == c2)
		ok2 = true;
	if (ok1 && !ok2)
		cout << "cw" << endl;
	else if (ok2 && !ok1)
		cout << "ccw" << endl;
	else
		cout << "undefined" << endl; 
	return 0;
}