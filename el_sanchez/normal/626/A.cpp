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

pii operator+(pii a, pii b) {
	return {a.X + b.X, a.Y + b.Y};	
}

int n;
string s;
map<char, pii> w;

int main() {

	w['U'] = {1, 0};
	w['D'] = {-1, 0};
	w['R'] = {0, 1};
	w['L'] = {0, -1};
	
	cin >> n;
	cin >> s;
	
	int ans = 0;
	for (int L = 0; L < n; L++)
		for (int R = L; R < n; R++) {
			pii cur = {0, 0};
			for (int i = L; i <= R; i++)
				cur = cur + w[s[i]];
			if (cur.X == 0 && cur.Y == 0)
				ans++;	
		}
		
	cout << ans << '\n';
		
	return 0;
}