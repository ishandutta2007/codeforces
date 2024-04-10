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
		int n, l;
		cin >> n >> l;
		vector <int> svi(n);
		REP(i, n) cin >> svi[i];
		vector <double> a1(n), a2(n);
		int brzina = 1;
		REP(i, n) {
			if(i == 0) a1[i] = svi[i];
			else a1[i] = a1[i - 1] + (double) (svi[i] - svi[i - 1]) / brzina;
			brzina++;
		}
		brzina = 1;
		for(int i = n - 1; i >= 0; i--) {
			if(i == n - 1) a2[i] = l - svi[i];
			else a2[i] = a2[i + 1] + (double) (svi[i + 1] - svi[i]) / brzina;
			brzina++;
		}
		/*int zas = 0;
		REP(i, n) {
			if(a1[i] > a2[i]) break;
			zas++;
		}
		double s = (double)((ll)(zas + 1) * (n - zas + 1) * ((zas == n ? 0 : a2[zas]) - (zas == 0 ? 0 : a1[zas - 1])) + (ll)(zas + 1) * (zas == n ? l - svi.back() : (zas == 0 ? svi[0] : svi[zas] - svi[zas - 1]))) / (zas + 1 + (n - zas + 1));
		cout << s << endl;*/
		double lo = 0, hi = a2[0] + (svi[0]), mid;
		REP(q, 100) {
			mid = (lo + hi) / 2;
			int z1 = 0, z2 = n - 1, b1, b2;
			double s1, s2, t1, t2;
			REP(i, n) {
				if(a1[i] > mid) break;
				z1++;
			}
			for(int i = n - 1; i >= 0; i--) {
				if(a2[i] > mid) break;
				z2--;
			}
			if(z1 == z2) {
				lo = mid;
				if(a1[z1] == a2[z2]) {
					lo = a1[z1];
					break;
				}
			}
			else if(z1 < z2) lo = mid;
			else {
				z1--; z2++;
				if(z1 < 0) {
					t1 = mid;
					b1 = 1;
					s1 = 0;
				}
				else {
					t1 = mid - a1[z1];
					b1 = 1 + z1 + 1;
					s1 = svi[z1];
				}
				if(z2 >= n) {
					t2 = mid;
					b2 = 1;
					s2 = l;
				}
				else {
					t2 = mid - a2[z2];
					b2 = n - z2 + 1;
					s2 = svi[z2];
				}
				//cout << s1 << " " << s2 << endl;
				s1 += t1 * b1;
				s2 -= t2 * b2;
				if(s1 < s2) lo = mid;
				else hi = mid;
				//cout << mid << " " << s1 << " " << s2 << endl;
			}
			if(lo > hi) break;
		}
		cout << fixed << setprecision(10) << lo << "\n";
	}
	return 0;
}