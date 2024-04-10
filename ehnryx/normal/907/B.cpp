#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string grid[3][3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> grid[i][k][j];
			}
		}
	}

	int a, b;
	cin >> a >> b;

	int gi = (a-1)%3;
	int gj = (b-1)%3;

	bool shit = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[gi][gj][i][j] == '.')
				shit = false;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (shit || i == gi && k == gj) {
					for (int l = 0; l < 3; l++) {
						if (grid[i][k][j][l] == '.')
							cout << "!";
						else
							cout << grid[i][k][j][l];
					}
					cout << " ";
				} else {
					cout << grid[i][k][j] << " ";
				}
			}
			cout << nl;
		}
		cout << nl;
	}

	return 0;
}