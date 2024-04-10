#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

bool prost(int x) {
	bool da = 1;
	for(int i = 2; i < x; i++) {
		if(x % i == 0) {
			da = 0;
			break;
		}
	}
	return da;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		int zad = 1, tr = n;
		while(!prost(tr) || prost(zad)) {
			tr++;
			zad++;
		}
		REP(i, n) {
			REP(j, n) {
				if(i == j) cout << zad << " ";
				else cout << "1 ";
			}
			cout << "\n";
		}
	}
	return 0;
}