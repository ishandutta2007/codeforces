#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1e9;
const int MAXN = 100500;

int n;

bool isPrime(int n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {

	while (cin >> n) {
		if (n == 2 || n == 3) {
			cout << 1 << '\n';
		} else if (!(n & 1)) {
			if (isPrime(n)) {
				cout << 1 << '\n';
			} else {
				cout << 2 << '\n';
			}
		} else {
			if (isPrime(n)) {
				cout << 1 << '\n';
			} else if (isPrime(n - 2)) {
				cout << 2 << '\n';
			} else {
				cout << 3 << '\n';
			}			
		}
	}
	
    return 0;
}