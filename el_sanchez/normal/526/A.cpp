#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const ld eps = 1e-14;
const int INF = 1E9;		                    
const int MAXN = 22222;
    
int n;
string s;

int main() { 
	
	cin >> n;
	cin >> s;
	forn(i, n) {
		if (s[i] != '*')
			continue;
		for (int j = i + 1; j < n; j++) {
			if (s[j] == '*') {
				int d = j - i, pos = i;
				bool f = 1;
				forn(k, 4) {
					pos += d;
					if (pos >= n || s[pos] == '.') {
						f = 0;
						break;
					}
				}

				if (f) {
					cout << "yes";
					return 0;
				}
			}
		}	}		
	cout << "no";
	
	return 0;
}