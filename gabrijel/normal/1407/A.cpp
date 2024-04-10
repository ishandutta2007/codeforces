#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		vector <int> rj;
		int a, b;
		REP(i, n / 2) {
			cin >> a >> b;
			if(a == b) {
				rj.push_back(a);
				rj.push_back(b);
			}
			else rj.push_back(0);
		}
		cout << (int)rj.size() << "\n";
		REP(i, (int)rj.size()) {
			cout << rj[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}