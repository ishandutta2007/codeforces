#include <bits/stdc++.h>
using namespace std;

vector<int> run(int n, string s) {
	vector<int> to_left(n);
	for(int i = 1; i < n; ++i) {
		if(s[i-1] == 'L') {
			to_left[i] = 1;
			if(i >= 2 && s[i-2] == 'R') {
				to_left[i] = to_left[i-2] + 2;
			}
		}
	}
	return to_left;
}

void test_case() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	n++;
	vector<int> to_left = run(n, s);
	reverse(s.begin(), s.end());
	for(char& c : s) {
		// if(c == 'L') c = 'R';
		// else c = 'L';
		c ^= ('L' ^ 'R');
	}
	vector<int> to_right = run(n, s);
	for(int i = 0; i < n; ++i) {
		int ans = to_left[i] + to_right[n-1-i] + 1;
		cout << ans << " ";
		// cout << to_left[i] << " " << to_right[n-1-i] << endl;
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
}