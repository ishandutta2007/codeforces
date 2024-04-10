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
	vi points;
	F0R(i, n) {
		int a;
		cin >> a;
		points.PB(a);
	}

	//Casework
	FOR(i, 0, n) {
		double slope, intercept;

		//Slope = rise over run
		if (i == 0) {
			slope = points.at(2) - points.at(1);
			//Intercept
			intercept = points.at(0);
			//cout << slope << endl;
		} else {

			slope = points.at(i) - points.at(0);
			slope /= i;

			//Intercept
			intercept = points.at(0);
		}

		double newIntercept = NAN;
		bool valid = true;
		FOR(j, 1, n) {
			if (isnan(newIntercept)) {
				//cout << slope * j + intercept << endl;
				if (abs(slope * j + intercept - points.at(j)) > .0000000000001) {
					newIntercept = points.at(j) - slope * j;
				}
			} else {
				if (abs(slope * j + intercept - points.at(j)) > .0000000000001 && abs(slope * j + newIntercept - points.at(j)) > .0000000000001) {
					valid = false;
				}
			}
		}
		if (isnan(newIntercept)) {
			valid = false;
		}
		if (valid) {
			/*cout << i << endl;
			cout << slope << endl;
			cout << intercept << endl;
			cout << newIntercept << endl;*/
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;

}