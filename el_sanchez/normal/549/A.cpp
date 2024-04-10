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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-11;
const int INF = 1E9;        
const int MAXN = 55;

int n, m;
bool used[4];
string s[MAXN];
string X = "face";

int main() {

	cin >> n >> m;
	forn(i, n)
		cin >> s[i];

	int ans = 0;
	forn(i, n - 1)
		forn(j, m - 1) {
		 	forn(k, 4)
		 		used[k] = 0;
		 	for (int a = i; a <= i + 1; a++)
		 		for (int b = j; b <= j + 1; b++)
		 			forn(d, 4)
		 				if (s[a][b] == X[d])
		 					used[d] = 1;
		 	bool f = 1;
		 	forn(k, 4)
		 		f &= used[k];
		 	ans += f;
		 	
		}
	cout << ans;
	return 0;
}