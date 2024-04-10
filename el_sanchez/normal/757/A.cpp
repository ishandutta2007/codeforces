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
const int MAXN = 555;

string S = "Bulbasaur";
string s;
int ans;
map<char, int> num;

int main() {

	while (cin >> s) {
		ans = 0;
		num.clear();
		forn(i, s.size()) {
			num[s[i]]++;
		}
		
		bool found = 1;
		while (found) {
			found = 0;
			for (int i = 0; i <= (int)S.size(); i++) {
				if (i == (int)S.size()) {
					found = 1;
					break;
				}
				if (num[S[i]] > 0) {
					num[S[i]]--;
				} else {
					break;
				}
			}
			
			ans += found;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}