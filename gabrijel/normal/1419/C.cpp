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
		int n, x;
		cin >> n >> x;
		int suma_raz = 0;
		bool postoji_raz = 0;
		int postoji_isti = 0;
		int a;
		vector <int> svi(n);
		REP(i, n) {
			cin >> a;
			svi[i] = a;
			if(a - x) postoji_raz = 1;
			else postoji_isti++;
			suma_raz += a - x;
		}
		if(!postoji_raz) cout << "0\n";
		else if(postoji_isti) {
			cout << "1\n";
		}
		else if(suma_raz == 0) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}