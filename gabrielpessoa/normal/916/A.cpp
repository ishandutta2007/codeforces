#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 2E5+5;
const int MOD = 1E6;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int main() {
	int x, h, m, but = 0;
	cin >> x >> h >> m;
	while(h % 10 != 7 && m % 10 != 7) {
		but++;
		m -= x;
		if(m < 0) {
			m += 60;
			h--;
			if(h == -1) h = 23;
		}
		//cout << h << " " << m << endl;
	}
	cout << but << endl;
	return 0;
}