#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}

vector <int> a, svi;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		a.clear();
		a.resize(n);
		svi.clear();
		svi.resize(n + 1);
		
		REP(i, n) {
			cin >> a[i];
			if(!i) svi[i] = a[i];
			else svi[i] = a[i] * a[i - 1] / gcd(a[i], a[i - 1]);
		}
		svi[n] = a[n - 1];
		bool ok = 1;
		REP(i, n) {
			if(gcd(svi[i], svi[i + 1]) != a[i]) {
				ok = 0;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}