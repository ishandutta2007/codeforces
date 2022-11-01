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
		vector <int> a(n);
		int zad = -1;
		REP(i, n) {
			cin >> a[i];
			if(i > 0 && a[i] < a[i - 1]) zad = i - 1;
		}
		if(zad == -1) {
			cout << "0\n";
			continue;
		}
		bool dalje = 0;
		int rj = 0;
		REP(i, n) {
			if(a[i] > x) {
				swap(a[i], x);
				rj++;
			}
			if(i < n - 1 && a[i] > a[i + 1]) dalje = 1;
			else dalje = 0;
			if(!dalje && i > zad) break;
		}
		zad = -1;
		REP(i, n) {
			if(i > 0 && a[i] < a[i - 1]) zad = i - 1;
		}
		if(zad != -1) cout << "-1\n";
		else cout << rj << "\n";
	}
	return 0;
}