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
const int INF = (int)1e9;
const int MAXN = 100500;
const int LEN = 20000;

int n, k;
string s;
int pos;
  
int main() {
	
	cin >> n;
	pos = 0;
	forn(i, n) {
		cin >> k >> s;
		char c = s[0];
		if (c == 'W' || c == 'E') {
			if (pos == 0 || pos == LEN) {
				cout << "NO\n";
				return 0;
			}
			continue;
		}
		
		if (c == 'S') {
			pos += k;
			if (pos > LEN) {
				cout << "NO\n";
				return 0;
			}
		} else if (c == 'N') {
			pos -= k;
			if (pos < 0) {
				cout << "NO\n";
				return 0;
			}			
		} else {
			assert(false);
		}
	}
	
	if (pos != 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	
	return 0;
}