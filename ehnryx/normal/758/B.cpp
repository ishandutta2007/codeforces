#include <bits/stdc++.h>
using namespace std;

int main() {
	int R, B, Y, G;
	int ans[4]; memset(ans, 0, sizeof(ans));
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R')
			R = i%4;
		if (s[i] == 'B')
			B = i%4;
		if (s[i] == 'Y')
			Y = i%4;
		if (s[i] == 'G')
			G = i%4;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '!') {
			if (i%4 == R)
				ans[0]++;
			else if (i%4 == B)
				ans[1]++;
			else if (i%4 == Y)
				ans[2]++;
			else if (i%4 == G)
				ans[3]++;
		}
	}
	for (int i = 0; i < 4; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}