#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int h, m, hr;
	h = (s[0]-'0')*10 + (s[1]-'0');
	hr = (s[0]-'0') + (s[1]-'0')*10;
	m = (s[3]-'0')*10 + (s[4]-'0');
	if (m <= hr && hr < 60) {
		cout << hr-m << endl;
	}
	else {
		int count = 0;
		h = (h+1)%24;
		hr = (h%10)*10 + (h/10);
		while (hr >= 60) {
			h = (h+1)%24;
			hr = (h%10)*10 + (h/10);
			count += 60;
		}
		cout << 60-m + hr + count << endl;
	}
	return 0;
}