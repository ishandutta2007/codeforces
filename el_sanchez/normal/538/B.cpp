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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

string s, cs;
int n, md;

int main() {

	cin >> s;
	n = s.size();
	forn(i, n) {
		md = max(md, s[i] - '0');	
	}
	
	cout << md << '\n';
	
	forn(i, md) {
		cs = s;
		forn(j, n) {
			if (s[j] != '0') {
				cs[j] = '1';
				s[j]--;	
			} else {
				cs[j] = '0';	
			}
		}
		
		while (cs[0] == '0')
			cs = cs.substr(1, cs.size() - 1);
		cout << cs << ' ';
	}
	cout << '\n';
	
	return 0;
}