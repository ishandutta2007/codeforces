#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<double, ll> di;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1E5+5;
const int MOD = 1E9+9;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-3;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;

string s[SIZE];
ii sh[SIZE];
di line[SIZE];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, h = 0, total = 0;
	cin >> n;
	for(ll i = 0; i < n; i++) {
		cin >> s[i];
		ll temph = 0, temps = 0;
		for(ll k = s[i].size() - 1; k >= 0; k--) {
			if(s[i][k] == 'h') {
				temph++;
			} else {
				total += temph;
				temps++;
			}
		}
		h += temph;
		sh[i] = ii(temps, temph);
		line[i] = di(temps == 0 ? INFF : temph*1.0/temps, i);
	}
	sort(line, line+n);
	for(ll i = 0; i < n; i++) {
		ll p = line[i].second;
		ll si = sh[p].first;
		ll hi = sh[p].second;
		//cout << line[i].first << " " << line[i].second << " " << si << " " << hi << " " << s[p] << '\n';
		h -= hi;
		total += si * h;
	}
	cout << total << '\n';
	return 0;
}