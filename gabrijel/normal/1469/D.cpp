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
		int n, a;
		cin >> n;
		vector <pair <int, int> > rj;
		if(n <= 256) {
			for(int i = 3; i < n; i++) {
				rj.push_back(make_pair(i, n));
			}
			a = n;
			while(a != 1) {
				rj.push_back(make_pair(n, 2));
				a = (a + 1) / 2;
			}
		}
		else {
			for(int i = 3; i < 15; i++) {
				rj.push_back(make_pair(i, n));
			}
			for(int i = 16; i < n; i++) {
				rj.push_back(make_pair(i, n));
			}
			a = n;
			while(a != 1) {
				rj.push_back(make_pair(n, 15));
				a = (a + 14) / 15;
			}
			a = 15;
			while(a != 1) {
				rj.push_back(make_pair(15, 2));
				a = (a + 1) / 2;
			}
		}
		cout << (int)rj.size() << "\n";
		for(pair <int, int> tr : rj) {
			cout << tr.first << " " << tr.second << "\n";
		}
	}
	return 0;
}