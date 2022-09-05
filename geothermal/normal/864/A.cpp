#include <bits/stdc++.h>

#define SQ(a) (a)*(a)

#define F0R(i, a) for(int i = 0; i < (a); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define R0F(i, a) for(int i = (a) - 1; i >= 0; i--)
#define ROF(i, a, b) for(int i = (b) - 1; i >= (a); i--)

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define UB upper_bound
#define LB lower_bound
#define X real()
#define Y imag()
#define MAXN 100000

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ld> point;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pii > v;
	F0R(i, n) {
		int x;
		cin >> x;
		if (v.size() < 2) {
			if (v.size() == 1 && x == v.at(0).first) {
				v.at(0).second++;
			} else {
				v.PB(MP(x, 1));
			}
		} else if (x == v.at(0).first) {
			v.at(0).second++;
		} else if (x == v.at(1).first) {
			v.at(1).second++;
		}

	}

	if (v.size() == 2 && v.at(0).second == n / 2 && v.at(1).second == n / 2) {
		cout << "YES" << endl << v.at(0).first << " " << v.at(1).first << endl;
	} else cout << "NO";

	return 0;

}