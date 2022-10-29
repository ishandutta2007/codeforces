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
const int INF = 1E9; 
const int MAXN = 100500;
const int ALPH = 27;

int n, m;
string s, res;
vi pos[ALPH];
int cover[MAXN];

bool covered() {
	int L = 0;
	int R = L + m - 1;
	for (int i = 0; i <= n && R < n; i++) {
		if (i == R + 1)
			return 0;
			
		if (i == n)
			break;
			
		if (cover[i]) {
			L = i + 1;
			R = L + m - 1;
		}
	}
	
	return 1;
}

int main() {

    cin >> m;
    cin >> s;
	n = s.size();
	res = "";
	
	forn(i, n)
		pos[s[i] - 'a'].pb(i);

	forn(c, ALPH) {
		for (auto i: pos[c])
			cover[i] = 1;

		if (covered()) {
			for (auto i: pos[c])
				cover[i] = 0;

			int L = 0;
			int R = L + m - 1;
			
			int ptr = 0;
			
			for (int i = 0; i <= n && R < n; i++) {
				if (i == R + 1) {
					assert(ptr > 0);
					int keep = pos[c][ptr - 1];
					assert(L <= keep && keep <= R);
					cover[keep] = 1;
					res += (char)('a' + c);	
					
					L = keep + 1;
					R = L + m - 1;
				}

				if (i == n)
					break;
						
				if (cover[i]) {
					L = i + 1;
					R = L + m - 1;
				}
				
				if (ptr < (int)pos[c].size() && pos[c][ptr] == i)
					ptr++;
			}
			
			break;
		} else {
			forn(j, pos[c].size())
				res += (char)('a' + c);	
		}
	}
	
	cout << res << '\n';		
	
	return 0;
}