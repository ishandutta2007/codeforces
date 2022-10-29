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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

string s[2], t[2];
string cur;
string res;
set<string> lib;
queue<string> q;

int main() {

	cin >> s[0] >> s[1];   
	cur = s[0] + s[1];
	cin >> t[0] >> t[1];   
	res = t[0] + t[1];
	
	lib.insert(cur);
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		s[0] = cur.substr(0, 2);
		s[1] = cur.substr(2, 2);
		//cout << s[0] << s[1] << '\n';
		
		forn(i, 2)
			forn(j, 2)
				if (s[i][j] == 'X') {
					forn(k, 2)
						forn(l, 2)
							if (abs(k - i) + abs(l - j) == 1) {
								swap(s[i][j], s[k][l]);

								if (lib.find(s[0] + s[1]) == lib.end()) {
									lib.insert(s[0] + s[1]);
									q.push(s[0] + s[1]);
								}
								
								swap(s[i][j], s[k][l]);
							}
				}
	}
	
	cout << (lib.find(res) == lib.end() ? "NO\n" : "YES\n");
	
	return 0;
}