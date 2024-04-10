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

string s;
int n;
int dp[MAXN][4];
string ns;
vector<string> answers;

int main() {

	cin >> s;
	n = s.size();
	reverse(all(s));
	
	dp[0][0] = 1;
	for (int i = 0; i < n - 5; i++) {
		for (int j = 0; j < 4; j++)
			if (dp[i][j]) {
				for (int k = 2; k <= 3; k++) {
					bool ok = 1;

					if (j == k) {
						ok = 0;
						for (int pos = 0; pos < k; pos++)
							if (s[i + pos] != s[i - k + pos])
								ok = 1;
					}
					
					if (ok)
						dp[i + k][k] = 1;
				}   					
			}
	}
	
	answers.clear();
	
	for (int i = 1; i <= n - 5; i++) {
		for (int j = 2; j <= 3; j++)
			if (dp[i][j]) {
				ns = "";
				forn(k, j)
					ns += s[i - 1 - k];
				answers.pb(ns);
			}
	}
	
	//forn(i, answers.size())
	//	reverse(all(answers[i]));
	sort(all(answers));
	answers.resize(unique(all(answers)) - answers.begin());
	
	cout << answers.size() << '\n';
	for (auto s: answers)
		cout << s << '\n';
		
	return 0;
}