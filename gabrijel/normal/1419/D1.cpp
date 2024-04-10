#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> svi(n);
	REP(i, n) {
		cin >> svi[i];
	}
	sort(svi.begin(), svi.end());
	reverse(svi.begin(), svi.end());
	int lo = 0, hi = n, mid;
	while(lo < hi) {
		mid = (lo + hi + 1) / 2;
		bool ne = 0;
		if(mid >= (n + 1) / 2) ne = 1;
		else {
			int zad = -1;
			int ptr_v = n - mid - 1, ptr_m = n - 1;
			while(ptr_m >= n - mid) {
				if(ptr_v < 0) {
					ne = 1;
					break;
				}
				while(ptr_v >= 0 && zad <= svi[ptr_m]) {
					zad = svi[ptr_v];
					ptr_v--;
				}
				if(ptr_v < 0) {
					ne = 1;
					break;
				}
				zad = -1;
				while(ptr_v >= 0 && zad <= svi[ptr_m]) {
					zad = svi[ptr_v];
					ptr_v--;
				}
				if(zad <= svi[ptr_m]) {
					ne = 1;
					break;
				}
				ptr_m--;
			}
		}
		if(ne) hi = mid - 1;
		else lo = mid;
	}
	cout << lo << "\n";
	if(lo == 0) {
		REP(i, n) cout << svi[i] << " ";
		cout << "\n";
		return 0;
	}
	int zad = -1;
	int ptr_v = n - lo - 1, ptr_m = n - 1;
	while(ptr_m >= n - lo) {
		while(ptr_v >= 0 && zad <= svi[ptr_m]) {
			zad = svi[ptr_v];
			cout << zad << " ";
			ptr_v--;
		}
		zad = -1;
		cout << svi[ptr_m] << " ";
		while(ptr_v >= 0 && zad <= svi[ptr_m]) {
			zad = svi[ptr_v];
			cout << zad << " ";
			ptr_v--;
		}
		ptr_m--;
	}
	while(ptr_v >= 0) {
		cout << svi[ptr_v] << " ";
		ptr_v--;
	}
	cout << "\n";
	return 0;
}