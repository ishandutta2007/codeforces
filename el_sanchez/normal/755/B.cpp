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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = (int)1e9;
const int MAXN = 100500;

int n[2];
int only[2], tog;
string s[MAXN];
set<string> lib;

int main() {
	
	while (cin >> n[0] >> n[1]) {
		only[0] = only[1] = tog = 0;
		
		lib.clear();
		forn(i, n[0]) {
			cin >> s[i];
			lib.insert(s[i]);
			only[0]++;
		}
		
		forn(i, n[1]) {
			cin >> s[i];
			if (lib.find(s[i]) == lib.end()) {
				only[1]++;
			} else {
				only[0]--;
				tog++;	
			}
		}
		
		bool step = 0;
		if (tog & 1) {
			step ^= 1;	
		}
		
		while (only[step] > 0) {
			only[step]--;
			step ^= 1;	
		}
		
		cout << (step ? "YES\n" : "NO\n");
	}
	
	return 0;
}