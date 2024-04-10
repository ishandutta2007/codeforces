#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 3E5+5;
const int MOD = 1E6;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	if(s.length() % k) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < s.length()/k; j++) {
			if(s[s.length()*i/k+j] != s[s.length()*(i+1)/k-1-j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}