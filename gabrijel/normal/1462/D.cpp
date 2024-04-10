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
		int n, suma = 0;
		cin >> n;
		vector <int> svi(n);
		REP(i, n) {
			cin >> svi[i];
			suma += svi[i];
		}
		for(int i = n; i >= 1; i--) {
			if(suma % i) continue;
			int target = suma / i;
			int tr_suma = 0, ptr = 0;
			bool ide = 1;
			while(ptr < n) {
				tr_suma += svi[ptr];
				if(tr_suma > target) {
					ide = 0;
					break;
				}
				else if(tr_suma == target) tr_suma = 0;
				ptr++;
			}
			if(ide) {
				cout << n - i << "\n";
				break;
			}
		}
	}
	return 0;
}