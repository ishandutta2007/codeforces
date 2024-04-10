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
const int INF = 1E9; 
const int MAXN = 100500;

int n;
ll a[MAXN];

int main() {

	cin >> n;
	a[0] = 2;
	for (int i = 1; i < n; i++) {
		int k = i + 1;
		a[i] = 1ll * k * (k + 1) * (k + 1) - (k - 1);
	}
	/*
	ll x = 2;
	forn(i, n) {
		x += 1ll * (i + 1) * a[i];
		cout << x << '\n';
		x = sqrtl(x);
		cout << x << '\n';
	}
	*/
	forn(i, n)
		cout << a[i] << '\n';
	
	return 0;
}