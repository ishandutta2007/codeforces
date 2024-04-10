#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> rj(n, 0);
	int ind = 1, odg1, odg2;
	for(int i = 2; i <= n; i++) {
		cout << "? " << ind << " " << i << "\n";
		cout << flush;
		cin >> odg1;
		cout << "? " << i << " " << ind << "\n";
		cout << flush;
		cin >> odg2;
		if(odg1 > odg2) {
			rj[ind - 1] = odg1;
			ind = i;
		}
		else {
			rj[i - 1] = odg2;
		}
	}
	REP(i, n) {
		if(rj[i] == 0) {
			rj[i] = n;
			break;
		}
	}
	cout << "! ";
	REP(i, n) cout << rj[i] << " ";
	cout << "\n";
	cout << flush;
	return 0;
}