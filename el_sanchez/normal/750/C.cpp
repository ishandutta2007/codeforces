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
const ld eps = 1e-9;
const int INF = (int)1e9;
const int MAXN = 200500;

const int INF2 = (int)1e8;
const int B = 1900;

int n;
int c[MAXN], d[MAXN];
pii cur, d1, d2;
  
pii intr(pii a, pii b) {
	return {max(a.X, b.X), min(a.Y, b.Y)};	
}

int main() {
	
	cin >> n;
	forn(i, n) {
		scanf("%d%d", &c[i], &d[i]);	
	}
	
	d1 = {B, INF};
	d2 = {-INF, B - 1};
	
	if (d[0] == 1) {
		cur = d1;
	} else {
		cur = d2;
	}
	
	for (int i = 0; i < n - 1; i++) {
		cur.X += c[i];
		cur.Y += c[i];

		if (d[i + 1] == 1) {
			cur = intr(cur, d1);
		} else {
			cur = intr(cur, d2);
		}
	}
	
	cur.X += c[n - 1];
	cur.Y += c[n - 1];
	
	if (cur.X > cur.Y) {
		cout << "Impossible\n";
	} else if (cur.Y >= INF2) {
		cout << "Infinity\n";	
	} else {
		cout << cur.Y << '\n';	
	}
	
	return 0;
}