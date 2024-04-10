#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n;
vector<int> v;
map<int, int> m;
map<int, bool> b;
int c[200000], d[200000];


int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> c[i] >> d[i];
		b[d[i]] = true;
		m[c[i]] = d[i];
	}
	int s;
	for (int i = 0; i < n; i++) {
		if (!b[c[i]] && c[i] != 0) {
			s = c[i];
			break;
		}
	}
	cout << s << ' ';
	int t[2];
	t[0] = s;
	for (int i = 0; i < n; i++) {
		if (c[i] == 0) {
			t[1] = d[i];
			break; 
		}
	}
	cout << t[1];
	for (int i = 2; i < n; i++) {
		cout << ' ' << m[t[0]];
		int x = m[t[0]];
		t[0] = t[1];
		t[1] = x;
	}
	cout << endl;
    return 0;
}