#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int a = 0;
	for (char c : s) {
		a += (c == 'a');
	}
	cout << int(s.size()) - max(0, int(s.size()) - a * 2 + 1) << endl;

	return 0;
}