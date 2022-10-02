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


string s;
long long a, b;
long long d[1000001], d1[1000001], d2[1000001];



int main() 
{
	cin >> s >> a >> b;
	if (s.size() < 2) {
		cout << "NO" << endl;
		return 0; 
	}
	for (int i = 0; i < s.size(); i++) {
		d[i] = ((i > 0 ? d[i - 1]: 0) * 10LL + s[i] - '0') % a;
	}
	d1[0] = 1 % b;
	for (int i = 1; i <= s.size(); i++) {
		d1[i] = (d1[i - 1] * 10LL) % b;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		d2[i] = ((i < s.size() - 1 ? d2[i + 1]: 0) + (s[i] - '0') * d1[s.size() - 1 - i]) % b;
	}
	for (int i = 0; i < s.size() - 1; i++) {
		if (d[i] == 0 && d2[i + 1] == 0 && s[i + 1] != '0') {
			cout << "YES" << endl;
			for (int j = 0; j <= i; j++) {
				cout << s[j];
			}
			cout << endl;
			for (int j = i + 1; j < s.size(); j++) {
				cout << s[j];
			}
			cout << endl;
			return 0;
		} 
	}
	cout << "NO" << endl;
    return 0;
}