#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		n *= 2;
		cin >> s;
		int b0 = 0, b1 = 0;
		REP(i, n) {
			if(s[i] == '0') b0++;
			else b1++;
		}
		if(b0 % 2 || b1 % 2) {
			cout << -1 << "\n";
			continue;
		}
		bool kaj = 0;
		vector <int> b;
		for(int i = 0; i < n; i += 2) {
			if(s[i] == s[i + 1]) continue;
			if(s[i] - '0' == kaj) b.push_back(i + 1);
			else b.push_back(i);
			kaj = !kaj;
		}
		cout << (int)b.size();
		for(int ind : b) cout << " " << ind + 1;
		cout << "\n";
		REP(i, n / 2) cout << i * 2 + 1 << " ";
		cout << "\n";
	}
	return 0;
}