#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1E5+5;
const int MOD = 1E6;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int digitos[10];
string a, b;

bool searchBest(int pos, int qualquerCoisa) {
	if(pos == a.size()) return true;
	if(qualquerCoisa) {
		for(int i = 9; i >= 0; i--) {
			if(digitos[i]) {
				digitos[i]--;
				a[pos] = i + '0';
				if(searchBest(pos + 1, 1)) return true;
				digitos[i]++;
			}
		}
		return false;
	}
	if(digitos[b[pos]-'0']) {
		digitos[b[pos]-'0']--;
		a[pos] = b[pos];
		if(searchBest(pos + 1, 0)) return true;
		digitos[b[pos]-'0']++;
	}
	for(int i = b[pos] - '0' - 1; i >= 0; i--) {
		if(digitos[i]) {
			digitos[i]--;
			a[pos] = i + '0';
			if(searchBest(pos + 1, 1)) return true;
			digitos[i]++;
		}
	}
	return false;
}

int main() {
	cin >> a >> b;
	if(b.size() > a.size()) {
		sort(a.rbegin(), a.rend());
		cout << a << endl;
		return 0;
	}
	for(int i = 0; i < a.size(); i++) {
		digitos[a[i]-'0']++;
	}
	searchBest(0, 0);
	cout << a << endl;
	return 0;
}