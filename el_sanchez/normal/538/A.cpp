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

int main() {

	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			cs = "";
			forn(k, n)
				if (!(i <= k && k <= j))
					cs += s[k];
			if (cs == "CODEFORCES") {
				cout << "YES";
				return 0;
			}			
		}
		
	cout << "NO";
	


	return 0;
}